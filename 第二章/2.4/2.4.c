#include<stdio.h>

void squeeze(char s1[],char s2[]) {
	int i, j, k;
	for (i = j = 0; s1[i] != '\0';i++) {
		for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++);
		if (s2[k] == '\0')
			s1[j++] = s1[i];
	}
	s1[j] = '\0';
	printf("йёоб%s", s1);
}
main() {
	char s1[20] = "hello";
	char s2[20] = "elo";
	squeeze(s1, s2);
}