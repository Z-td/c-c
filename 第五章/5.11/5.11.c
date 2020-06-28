#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define Tabsize 8

int getline(char line[], int maxline);
void detab(char* s, char* t, int tabsize);
void entab(char* s, char* t, int tabsize);

int main(int argc, char* argv[])
{
	char origin[MAXLINE];
	char result[MAXLINE];
	int tabsize;

	if (argc < 2)
		tabsize = Tabsize;
	else if (argc == 2)
	{
		tabsize = atoi(argv[1]);
		if (tabsize < 1)
		{
			printf("please enter a positive number\n");
			return -1;
		}
	}
	else
	{
		printf("error!\n");
		return -1;
	}

	printf("��������Ʊ�����ַ�����\n");
	while (getline(origin, MAXLINE) > 0)
	{
		detab(origin, result, tabsize);
		printf("detab : \n%s\n", result);

		printf("��������ո���ַ�����\n");
		getline(origin, MAXLINE);
		entab(origin, result, tabsize);
		printf("entab : \n%s\n", result);

		printf("����������Ʊ�����ַ���\n");
	}
	return 0;
}

void detab(char* s, char* t, int tabsize)
{
	int all, size;//all�ַ�����size�ַ�λ

	for (all = 0, size = 0; *s; s++)
	{
		if (*s == '\t')
		{
			size = tabsize - (all % tabsize);//�ո�ռ�ַ�����
			while (size > 0)
			{
				*t++ = ' ';
				all++;
				size--;
			}
		}
		else
		{
			*t++ = *s;
			all++;
		}
	}
	*t = *s;
}
void entab(char* s, char* t, int tabsize)
{
	int all, space;//all�ַ�����space�ո�
	for (all = 0, space = 0; *s; s++)
	{
		if (*s == ' ')
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
			if (space > 0)//��ӡ�ո�
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
