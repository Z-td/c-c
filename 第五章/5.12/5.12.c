#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINE 1000
#define Tabsize 8

int getline(char line[], int maxline);
void detab(char* s, char* t, int tabsize, int m);
void entab(char* s, char* t, int tabsize, int m);

int main(int argc, char* argv[])
{
	char origin[MAXLINE];
	char result[MAXLINE];
	int tabsize;
	int m;

	if (argc == 1)
	{
		m = 1;
		tabsize = Tabsize;
	}
	else if (argc == 3)
	{
		while (--argc)
		{
			if (*(*++argv) == '-' && isdigit(*++(*argv)))
				m = atoi(*argv);
			else if (**argv == '+' && isdigit(*++(*argv)))
				tabsize = atoi(*argv);
			else
			{
				printf("parameter error\n");
				return -1;
			}
		}
	}
	else
	{
		printf("error!\n");
		return -1;
	}

	printf("请输入带制表符的字符串：\n");
	while (getline(origin, MAXLINE) > 0)
	{
		detab(origin, result, tabsize, m);
		printf("detab : \n%s\n", result);

		printf("请输入带空格的字符串：\n");
		getline(origin, MAXLINE);
		entab(origin, result, tabsize, m);
		printf("entab : \n%s\n", result);

		printf("继续输入带制表符的字符串\n");
	}
	return 0;
}

void detab(char* s, char* t, int tabsize, int m)
{
	int all, size;

	for (all = 0, size = 0; *s; s++)
	{
		if (*s == '\t' && (all >= (m - 1)))
		{
			size = tabsize - (all % tabsize);
			while (size > 0)
			{
				*t++ = ' ';
				all++;
				size--;
			}
		}
		else if (*s == '\t')
		{
			size = tabsize - (all % tabsize);
			while (size > 0)
			{
				all++;
				size--;
			}
			*t++ = '\t';
		}
		else
		{
			*t++ = *s;
			all++;
		}
	}
	*t = *s;
}
void entab(char* s, char* t, int tabsize, int m)
{
	int all, space;
	for (all = 0, space = 0; *s; s++)
	{
		if (*s == ' ' && (all >= (m - 1)))
		{
			if (all % tabsize != tabsize - 1)
				space++;

			else if (all % Tabsize == tabsize - 1)
			{
				space = 0;
				*t++ = '\t';
			}
			all++;
		}
		else
		{
			if (space > 0)
			{
				while (space > 0)
				{
					*t++ = ' ';
					space--;
				}
			}
			*t++ = *s;
			all++;
		}
	}
	*t = *s;
}

int getline(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;

	if (c == '\n')
	{
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
