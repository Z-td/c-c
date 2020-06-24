#include<stdio.h>

void itoa(int n,char s[],int m);
void reverse(char s[]);
main() {
	int n;
	n = 12124;
	char s[50];
	itoa(n, s, 20);
	printf("%s", s);

}

void itoa(int n,char s[],int m) 
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do
	{
		s[i++] = n % 10 + '0';
	} while ((n/=10)>0);
	if (sign < 0)
		s[i++] = '-';
	for (; i < m; s[i++] = ' ');
	s[i] = '\0';
	reverse(s);
}

void reverse(char s[]) {

	int c, i, j;
	for ( i = 0, j = strlen(s)-1;i<j; i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}