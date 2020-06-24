#include<stdio.h>
main() {
	char s[20];
	char c;
	int i = 0;
	while ((c = getchar()) != EOF && (c != ' ') && (c != '\n'))
	{
		s[i++] = c;
	}
	s[i] = ' ';
	printf("%d\n", htoi(s));
}
int htoi(char s[]) {
	int d = 0, e = 0, f;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		d = 2;
	}
	int j = 0;
	while (s[j++] != ' ') {
	}
	f = j - 2;
	for (int i = 1; f >= d; i = i * 16) 
	{
		if (s[f] >= '0' && s[f] <= '9') 
		{
			e = e + (s[f] - '0') * i;
		}
		else if (s[f] >= 'a' && s[f] <= 'f') 
		{
			e = e + (s[f] - 'a' + 10) * i;
		}
		else if (s[f] >= 'A' && s[f] <= 'F') 
		{
			e = e + (s[f] - 'A' + 10) * i;
		}
		f--;
	}
	return e;
}