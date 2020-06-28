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

void undcl(void);
int gettoken(void);
void delete_parens(char* s);//删除多余的圆括号

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
			strcpy(token, "()");//当读取的'('后面紧跟')'时，说明这是一个函数标记
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
