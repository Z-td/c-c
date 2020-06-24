#include <stdio.h>
void itob(int n, char s[], int b);
main() {
	int n = 100;
	char s[50];

	itob(n, s, 16);
	printf("%s ", s);

	itob(n, s, 8);
	printf("%s ", s);

	itob(n, s, 4);
	printf("%s ", s);

	itob(n, s, 2);
	printf("%s ", s);

}
void itob(int n, char s[], int b) {
	int i = 0;
	while (n!=0) {
		s[i++] = n % b + '0';
		n /= b;
	}
	s[i--] = '\0';
	for (int j = 0; j < i; ++j, --i) {
		char temp = s[j];
		s[j] = s[i];
		s[i] = temp;
	}
}
