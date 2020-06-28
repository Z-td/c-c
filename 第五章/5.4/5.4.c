#include <stdio.h>

#define MAXSIZE 100

int strend(char* s, char* t);

int main(void)
{
	int result;
	char string1[MAXSIZE] = "Hello world!";
	char string2[MAXSIZE] = "ld!";
	char string3[MAXSIZE] = "rld";

	result = strend(string1, string2);
	printf("%d\n", result);

	result = strend(string1, string3);
	printf("%d\n", result);

	return 0;
}

int strend(char* s, char* t)
{
	int t_len = 0;
	int s_len = 0;

	while (*s)
	{
		s++;
		s_len++;
	}
	s--;

	while (*t)
	{
		t++;
		t_len++;
	}
	t--;

	if (s_len >= t_len)
	{
		for (; *s == *t && t_len > 0; t_len--, s--, t--)
			;
		if (t_len == 0)
			return 1;
	}
	return 0;
}
