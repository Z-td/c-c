#include <stdio.h>

#define MAXSIZE 100

void strncpy(char* s, char* t, int n);
void strncat(char* s, char* t, int n);
int strncmp(char* s, char* t, int n);

int main(void)
{
	int number = 4;
	char string1[MAXSIZE];
	char string2[MAXSIZE] = "Hello";
	char string3[MAXSIZE] = "World!";
	char string4[MAXSIZE] = "Hel";

	strncpy(string1, string2, number);
	printf("%s\n", string1);

	strncat(string2, string3, number);
	printf("%s\n", string2);

	printf("%d\n", strncmp(string2, string4, number));

	return 0;
}

void strncpy(char* s, char* t, int n)
{

	if (n <= 0)
	{
		printf("please enter a positive number\n");
		return;
	}
	for (; (*s++ = *t++) && n > 0; n--)
		;
	*--s = '\0';
}

void strncat(char* s, char* t, int n)
{
	if (n <= 0)
	{
		printf("please enter a positive number\n");
		return;
	}
	while (*s++)
		;
	s--;
	for (; (*s++ = *t++) && n > 0; n--)
		;
	*--s = '\0';
}

int strncmp(char* s, char* t, int n)
{
	if (n <= 0)
	{
		printf("please enter a positive number\n");
		return EOF;
	}
	for (; (*s == *t) && n > 0 && *t != '\0'; n--)
	{
		s++;
		t++;
	}
	if (n == 0 || *t == '\0')
		return 0;
	else if (*s > * t)
		return 1;
	else
		return -1;
}
