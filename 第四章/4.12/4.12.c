#include <stdio.h>

#define MAXSIZE 1000

void itoa(int n, char s[]);

int main(void)
{
	int number = 0;
	char string[MAXSIZE];

	printf("请输入一个数字\n");
	scanf_s("%d", &number);

	itoa(number, string);
	printf("%s\n", string);
	return 0;
}

void itoa(int n, char s[])
{
	static int i = 0;
	unsigned int u;

	if (n < 0)
	{
		u = -n;
		s[i++] = '-';
	}
	else
		u = n;

	if ((u / 10) > 0)
		itoa(u / 10, s);

	s[i++] = u % 10 + '0';

	s[i] = '\0';
}