#include<stdio.h>
int binsearch(int x, int v[], int n);

 main()
 {
	 int v[20];
	 int i, x, n;
	 x = 8;
	 for (i = 0; i < 20; ++i)
		 v[i] = i;
	 n = 20;
	 int result = binsearch(x, v, n);
	 printf("%d", result);
}
int binsearch(int x, int v[], int n)
{
	int low, heigh, mid;
	low = 0;
	heigh = n - 1;
	mid = (low + heigh) / 2;
	while (low <= heigh && x != v[mid])
	{
		if (x < v[mid]) heigh = mid - 1;
		else low = mid + 1;
		mid = (low + heigh) / 2;
	}
	if (x == v[mid])
		return mid;
	else
		return -1;
}