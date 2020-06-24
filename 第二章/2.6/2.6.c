#include <stdio.h>
 int main()
 {
	    unsigned x, y, result;
	    int p, n;
	    // scanf_s("%d %d %d %d", &x, &p, &n, &y);
	 x = 1250;
	 p = 2;
	 n = 3;
	 y = 4750;
		     result = setbits(x, p, n, y);
	    printf("The result is : %d\n", result);
	
	 }

unsigned setbits(unsigned x ,int p,int n,unsigned y) {
	     return  (x & ~(~(~0 << n) << (p + 1 - n))) | ((y & ~(~0 << n)) << (p + 1 - n));
	
}