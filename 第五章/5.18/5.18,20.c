#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXTOKEN 100
#define BUFSIZE 100
#define DATATYPE "int short long char float double void"

enum { NAME, PARENS, BRACKETS };


int tokentype;//最后一次输入的符号类型
char token[MAXTOKEN];//最后一个符号字符串
char name[MAXTOKEN];//标识符名
char datatype[MAXTOKEN];//数据类型，包括char、int等
char out[1000];
char buf[BUFSIZE];
int bufp = 0;

void dcl(void);
void dirdcl(void);
int gettoken(void);

int main(void)
{
	int const_mask = 0;

	while (gettoken() != EOF)//读取第一个输入的符号
	{
		if (!strcmp(token, "const") && !const_mask)
		{
			const_mask = 1;
			strcpy_s(' ',datatype, "const ");
			gettoken();
		}

		if (strstr(DATATYPE, token) != NULL)//程序只能接受单名的数据类型
			strcat_s(' ',datatype, token);//正常情况下声明的第一个符号是数据类型，即int、long、char等，但是为了排除错误，加入一条判断
		else
			printf("can't identify the \"%s\" datatype\n", token);

		out[0] = '\0';

		dcl();        //解析声明的其余部分
		if (tokentype != '\n')
			printf("syntax error\n");

		printf("%s: %s %s\n", name, out, datatype);
		const_mask = 0;
		datatype[0] = '\0';
	}
	return 0;
}

int gettoken(void)//返回下一个符号
{
	int c, getch(void);
	void ungetch(int);
	char* p = token;//指针p每次进入函数时都是指向token数组的首元素

	while ((c = getch()) == ' ' || c == '\t')
		;
	if (c == '(')
	{
		if ((c = getch()) == ')')
		{
			strcpy_s('  ',token, "()");//当读取的'('后面紧跟')'时，说明这是一个函数标记
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
		for (*p++ = c; (*p++ = getch()) != ']'; )//从[开始读取，直到读取到]退出循环
			;
		*p = '\0';
		return tokentype = BRACKETS;//返回中括号标记
	}
	else if (isalpha(c))
	{
		for (*p++ = c; isalnum(c = getch()); )//读取整个标识符名
			*p++ = c;
		*p = '\0';
		ungetch(c);
		return tokentype = NAME;//返回变量名或者类型名标记
	}
	else
		return tokentype = c;
}

void dcl(void)//解析一个声明
{
	int ns;
	int const_mask = 0;
	for (ns = 0; gettoken() == '*' || !strcmp(token, "const"); )//计算*的数量
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

void dirdcl(void)//解析直接声明符
{
	int type;
	if (tokentype == '(')
	{
		dcl();
		if (tokentype != ')')
			printf("error: missing ) \n");
	}

	else if (tokentype == NAME)//变量名
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
