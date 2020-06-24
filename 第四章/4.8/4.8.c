#include <stdio.h>

int bufp = EOF;
void ungets(char s[]);
int getch(void);
void ungetch(int);


int main(void)
{
	int c;
	while ((c = getch()) != EOF)
	{
		if (c == '\n')
			ungetch('*');
		putchar(c);
	}

	return 0;
}

int getch(void)
{
	int c;
	c = (bufp == EOF) ? getchar() : bufp;
	bufp = EOF;
	return c;
}

void ungetch(int c)
{
	if (bufp != EOF)
		printf("ungetch: too many characters\n");
	else
		bufp = c;
}