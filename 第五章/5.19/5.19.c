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

void undcl(void);
int gettoken(void);
void delete_parens(char* s);//ɾ�������Բ����

int main(void)
{
	int type, prev_type;
	char temp[MAXTOKEN];

	while (gettoken() != EOF)
	{
		strcpy(out, token);
		prev_type = NAME;
		while ((type = gettoken()) != '\n')
		{
			if (type == PARENS || type == BRACKETS)
				strcat(out, token);

			else if (type == '*')
			{
				if (prev_type == '*')
					sprintf(temp, "*%s", out);
				else
					sprintf(temp, "(*%s)", out);
				strcpy(out, temp);
			}

			else if (type == NAME)
			{
				if (strstr(DATATYPE, token) == NULL)
					printf("can't identify \"%s\" datatype\n", token);

				if (prev_type == '*')
					delete_parens(out);

				sprintf(temp, "%s %s", token, out);
				strcpy(out, temp);
			}

			else
				printf("invalid input at %s\n", token);

			prev_type = type;
		}
		printf("%s\n", out);
	}
	return 0;
}
void delete_parens(char* s)
{
	if (*s == '(')
	{
		while (*(s + 1) != '\0')
		{
			*s++ = *(s + 1);
		}
		*--s = '\0';
	}
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
			strcpy(token, "()");//����ȡ��'('�������')'ʱ��˵������һ���������
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
