#include <stdlib.h>
#include<stdio.h>
int rightrot(int x, int n);
int main()
{
	int x, n;
	printf("输入数：");
	scanf_s("%d", &x);
	printf("移动位数");
	scanf_s("%d", &n);
	printf("Result=%d\n", rightrot(x, n));
	/*system("pause");*/
	return 0;
}
int rightrot(int x, int n)
{
	int i, j, cc, tmp1, tmp2;
	for (j = x, cc = 0; j != 0; j /= 2, cc++);
	for (i = 0; i < n; i++) {
		tmp1 = x >> 1 << 1;
		tmp2 = (((tmp1 ^ x) << cc) + tmp1) >> 1;
		x = tmp2;
	}
	return x;
}
