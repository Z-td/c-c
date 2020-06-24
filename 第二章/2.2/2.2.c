
#include<stdio.h>
#define lim 100;

main() {
	int i = 0, c;
	char s[lim];
	while (i < lim - 1) {
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;
		++i;
		s[i] = c;
	}
	
}
