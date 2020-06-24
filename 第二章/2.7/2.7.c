#include<stdio.h>

main() {
	unsigned x;
	int p, n, result;
	/*scanf_s("%d%d%d", &x, &p, &n);*/
	x = 144;
	p = 5;
	n = 2;
	result = invert(x, p, n);
	printf("%d", result);
}
unsigned invert(unsigned x,int p,int n) {
	return  (x & ~(~(~0 << n) << (p + 1 - n))) | (x >> (p + 1 - n) ^ ~(~0 << n)) << (p + 1 - n);
}