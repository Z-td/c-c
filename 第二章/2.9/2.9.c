#include<stdio.h>

int bitcount(unsigned x) {
	int b;
	for (b = 0; x != 0; x & (x - 1))
		b++;
	return b;
}
main() {
	int a = bitcount(1511);
	printf("%d", a);
}
