#include <stdio.h>
#include<string.h>
#include <climits>
main() {
	printf("schar %d %d\n", SCHAR_MAX, SCHAR_MIN);
	printf("sshort %d %d\n", SHRT_MAX, SHRT_MIN);
	printf("sint %d %d\n", INT_MAX, INT_MIN);
	printf("slong %d %d\n", LONG_MAX, LONG_MIN);

	printf("ulong %d %u\n", 0, ULONG_MAX);
	printf("ushort %d %d\n", 0, USHRT_MAX);
	printf("uchar %d %d\n", 0, UCHAR_MAX);
	printf("uint %d %u\n", 0, UINT_MAX);
}