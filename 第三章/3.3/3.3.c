#include <stdio.h>
void expand(char s1[], char s2[]);
int main() {
	char s1[20] = "-a-f0-9-S-X";
	char s2[100] = "";
	expand(s1, s2);
	for (int i = 0; s2[i] != '\0'; ++i) {
		printf("%c", s2[i]);
	}
	return 0;
}
void expand(char s1[], char s2[]) {
	int i, j=0;
	for ( i = 0; s1[i]!='\0'; i++)
	{
		if (s1[i] == '-') {
		    
			if (i == 0)
			{
				s2[j++] = '-';
			}
			else if (s1[i - 1] >= 'a' && s1[i - 1] <= 'z' && s1[i + 1] >= 'a' && s1[i + 1] <= 'z')
			{
				for (char k = s1[i - 1] + 1; k < s1[i + 1];++k) {
					s2[j++] = k;
				}
			}
			else if(s1[i - 1] >= 'A' && s1[i - 1] <= 'Z' && s1[i + 1] >= 'A' && s1[i + 1] <= 'Z')
			{
				for (char k = s1[i - 1] + 1; k < s1[i + 1]; ++k) {
					s2[j++] = k;
				}
			}
			else if (s1[i - 1] >= '0' && s1[i - 1] <= '9' && s1[i + 1] >= '0' && s1[i + 1] <= '9')
			{
				for (char k = s1[i - 1] + 1; k < s1[i + 1]; ++k) {
					s2[j++] = k;
				}
			}
			else
			{
				s2[j++] = '-';
			}
		}
		else
		{
			s2[j++] = s1[i];
		}
	}
	s2[j] = '\0';
}