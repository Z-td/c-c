#include<stdio.h>
void itoa(int n, char s[]);
void reverse(char s[]);
int main()
{
	int n = 5842;
	char s[100];
	itoa(n, s);
	for (int i = 0; s[i] != '\0'; ++i) {
		printf("%c", s[i]);
	}
	printf("\n");
}
void itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}


void reverse(char s[]) {
	int i;
	for (i = 0; s[i] != '\0'; ++i) {
		;
	}
	--i;
	for (int j = 0; i > j; --i, ++j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}
