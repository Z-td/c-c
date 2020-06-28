#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100
#define DATATYPE "int short long char float double void"

enum { NAME, PARENS, BRACKETS };


int tokentype;//���һ������ķ�������
char token[MAXTOKEN];//���һ�������ַ���
char name[MAXTOKEN];//��ʶ����
char datatype[MAXTOKEN];//�������ͣ�����char��int��
char out[1000];
char buf[BUFSIZE];
int bufp = 0;

void dcl(void);
void dirdcl(void);
int gettoken(void);

int main(void)
{
	int const_mask = 0;

	while (gettoken() != EOF)//��ȡ��һ������ķ���
	{
		if (!strcmp(token, "const") && !const_mask)
		{
			const_mask = 1;
			strcpy_s(' ',datatype, "const ");
			gettoken();
		}

		if (strstr(DATATYPE, token) != NULL)//����ֻ�ܽ��ܵ�������������
			strcat_s(' ',datatype, token);//��������������ĵ�һ���������������ͣ���int��long��char�ȣ�����Ϊ���ų����󣬼���һ���ж�
		else
			printf("can't identify the \"%s\" datatype\n", token);

		out[0] = '\0';

		dcl();        //�������������ಿ��
		if (tokentype != '\n')
			printf("syntax error\n");

		printf("%s: %s %s\n", name, out, datatype);
		const_mask = 0;
		datatype[0] = '\0';
	}
	return 0;
}

int gettoken(void)//������һ������
{
	int c, getch(void);
	void ungetch(int);
	char* p = token;//ָ��pÿ�ν��뺯��ʱ����ָ��token�������Ԫ��

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getch()) == ')')
		{
			strcpy_s('  ',token, "()");//����ȡ��'('�������')'ʱ��˵������һ���������
			return tokentype = PARENS;
		}

		else
		{
			ungetch(c);
			return tokentype = '(';
		}
	}
	else if (c == '[')
	{
		for (*p++ = c; (*p++ = getch()) != ']'; )//��[��ʼ��ȡ��ֱ����ȡ��]�˳�ѭ��
			;
		*p = '\0';
		return tokentype = BRACKETS;//���������ű��
	}
	else if (isalpha(c))
	{
		for (*p++ = c; isalnum(c = getch()); )//��ȡ������ʶ����
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;//���ر������������������
	}
	else
		return tokentype = c;
}

void dcl(void)//����һ������
{
	int ns;
	int const_mask = 0;
	for (ns = 0; gettoken() == '*' || !strcmp(token, "const"); )//����*������
	{
		if (tokentype == '*')
		{
			ns++;
			const_mask = 0;
		}
		else
		{
			if (ns > 0 && !const_mask)
				const_mask = 1;
			else
				printf("\"const\" location error\n");
		}
	}
	dirdcl();
	while (ns-- > 0)
	{
		if (const_mask)
			strcat_s(' ',out, " const pointer to");
		else
			strcat_s(' ',out, " pointer to");
	}
}

void dirdcl(void)//����ֱ��������
{
	int type;
	if (tokentype == '(')
	{
		dcl();
		if (tokentype != ')')
			printf("error: missing ) \n");
	}

	else if (tokentype == NAME)//������
		strcpy_s(' ',name, token);
	else
		printf("error: expected name or (dcl)\n");
	while ((type = gettoken()) == PARENS || type == BRACKETS)
		if (type == PARENS)
			strcat_s(' ',out, " function returning");
		else
		{
			strcat_s(' ',out, " array");
			strcat_s(' ',out, token);
			strcat_s(' ',out, " of");
		}
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
