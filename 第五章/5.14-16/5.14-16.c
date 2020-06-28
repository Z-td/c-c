#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 100
#define MAXLEN 1000
#define ALLOCSIZE 10000

char* lineptr[MAXLINES];
char allocbuf[ALLOCSIZE];
char* allocp = allocbuf;

int readlines(char* lineptr[], int maxlines);
void printlines(char* lineptr[], int n, int nlines);
int getline(char s[], int lim);
char* alloc(int n);
void afree(char* p);

int main(int argc, char* argv[])
{
	int n;
	int nlines = 0;

	if (argc == 2)//合理输入的情况下
	{
		if (*(*++argv) == '-' && isdigit(*++(*argv)))
			n = atoi(*argv);
		else if (isdigit(**argv))
			n = atoi(*argv);
		else
			n = 10;
	}
	else
		n = 10;

	if ((nlines = readlines(lineptr, MAXLINES)) > 0)
	{
		if (nlines < n)
			printlines(lineptr, 0, nlines);
		else
			printlines(lineptr, n, nlines);
	}
	else
	{
		printf("error: input is empty\n");
		return -1;
	}

	afree(allocbuf);

	return 0;
}

int readlines(char* lineptr[], int maxlines)
{
	int len, nlines;
	char* p, line[MAXLEN];

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0)
	{
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else
		{
			line[len - 1] = '\0';
			strcpy_s(' ',p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

void printlines(char* lineptr[], int n, int nlines)
{
	for (int i = nlines - n; i < nlines; i++)
		printf("%s\n", lineptr[i]);
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

char* alloc(int n)
{
	if (allocp + n <= allocbuf + ALLOCSIZE)
	{
		allocp += n;
		return allocp - n;
	}
	else
		return NULL;
}

void afree(char* p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
