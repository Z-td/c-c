#include <stdio.h>
#include<ctype.h>

#define ISP(aa) ((aa >= 'A' && aa <= 'Z') ? 1 : 0;)
main() {
	int aa = 'a';
	int a = isupper(aa);
	int b = isper(aa);
	printf("%d%d", a,b);


}



int isper(char aa) {
	return (aa >= 'A' && aa <= 'Z');
}