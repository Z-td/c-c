#include <stdio.h>

#define MAXSIZE 100

void strcat(char* s, char* t);

int main(void)
{
	char string1[MAXSIZE] = "Hello world!";
	char string2[MAXSIZE] = "good morning";

	strcat(string1, string2);

	printf("%s\n", string1);
	return 0;
}

void strcat(char* s, char* t)
{
	while (*s++)
		;
	
	s--;
	while (*s++ = *t++)
		;
}
