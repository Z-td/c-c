#include <stdio.h>
#include <string.h>

#define MAXSIZE 100
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

void ungets(char s[]);

int getch(void);
void ungetch(int);


int main(void)
{
	char string[MAXSIZE] = "It's a test statement";
	int c;

	ungets(string);
	while ((c = getch()) != EOF)
		putchar(c);

	return 0;
}

void ungets(char s[])
{
	int length = strlen(s);
	while (length > 0)
	{
		ungetch(s[--length]);
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
