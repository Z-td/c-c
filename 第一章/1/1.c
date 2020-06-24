#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0
#define MAXHIST;
#define MAXWORD;
int getline(char line[], int maxline);
void copy(char to[], char from[]);
main() {
	printf("1.1：\n");
	printf("hello,world\n");

	printf("1.2：\n");
	printf("hello,world\c\n");

	printf("1.3：\n");
	float  fahr, ceksius;
	int lower, upper, step;
	lower = 0; /*下限*/
	upper = 300; /*上限*/
	step = 20;/*步长*/
	fahr = lower;
	printf("华氏度转摄氏度\n");
	while (fahr <= upper)
	{
		ceksius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, ceksius);
		fahr = fahr + step;
	}

	printf("1.4：\n");
	printf("摄氏度转华氏度\n");
	fahr = 0;
	while (fahr <= upper)
	{
		ceksius = fahr * (9.0 / 5.0) + 32;
		printf("%3.0f %3.1f\n", fahr, ceksius);
		fahr = fahr + step;
	}

	printf("1.5\n");
	int newfahr;
	for (newfahr = 300; newfahr >= 0; newfahr = newfahr - 20)
		printf("%3d %6.1f\n ", newfahr, (5.0 / 9.0) * (newfahr - 32));

	printf("1.6\n");
	int a;
	while(a = getchar() != EOF);
	printf("%d", a);

	printf("\n1.7\n");
	printf("%d", EOF);

	printf("\n1.8\n");
	int b, c;
	b = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n' || c == ' ' || c == '\t')
			++b;
	printf("%d\n", b);

	printf("1.9\n");
	char d;
	int e = 0;
	while ((d = getchar()) != EOF)
	{
		if (d == ' ') {
			if (e == 0)
			{
				putchar(d);
				e = 1;
			}
			else
			{
				putchar(d);
				e = 0;
			}
		}
	}

	printf("\n1.10\n");
	char f;
	f = "123\b159\t158\b";
	while ((f = getchar()) != EOF)
	{
		if (f == '\t')
			printf("\\t");

		if (f == '\b')
			printf("\\b");

		if (f == '\\')
			printf("\\\\");

		if (f != '\t' && f != '\b' && f != '\\')
			putchar(f);

	}
	printf("\n1.11\n");
	char g;
	int n1, nw, nc, state;

	state = OUT;
	n1 = nw = nc = 0;

	while ((g = getchar()) != EOF)
	{
		++nc;
		if (g == '\n')
			++n1;

		if (g == ' ' || g == '\n' || g == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}

	}

	printf("%d %d %d \n", n1, nw, nc);



	printf("\n1.12\n");
	char g;
	int n1, nw, nc, state;

	state = OUT;
	n1 = nw = nc = 0;

	while ((g = getchar()) != EOF)
	{
		++nc;
		if (g == '\n')
			++n1;

		if (g == ' ' || g == '\n' || g == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
			putchar('\n');
			putchar(g);
		}
		else if (state == IN)
		{
			putchar(g);
		}

	}

	printf("%d %d %d \n", n1, nw, nc);



	printf("\n1.13\n");
	int h, i, j, stat,len,maxvalue,overflow,wl[MAXHIST];
	stat = OUT;
	j = 0;
	overflow = 0;
	for ( i = 0; i < maxvalue; i++)
	{
		wl[i] = 0;
	}
	while ((c = getchar()) !=EOF）
	{
			if(c == ''||c == '\'||c =='\t')
			{
				stat = OUT;
				if (j > 0) 
				{
					if (MAXHIST)
					{
						++wl[j];
					}
					else
					{
						++overflow;
					}
					j = 0;
				}
		     }
				else if(stat == out)
	           {
			   stat = IN;
			   j = 1;
			   }
				else
	            {
				++j;
	            }
	}
	maxvalue = 0;
	for ( i = 1; i < MAXWORD; i++)
	{
		printf("%5d - %5d",i,wl[i])
			if (wl[i]>0)
			{
				if ((len = wl[MAXHIST])<=0)
				{
					len = 1;
				}

			}
			else
			{
				len = 0;
			}
		while (len>0)
		{
			putchar('*');
			--len;

		}
		putchar('\n');
		      
	}

	if (ovflow > 0) {
	
	printf("%d/n",ovflow,MAXWORD)
	}




	/*int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len - getline(line,MAXLINE)) > 0)
		if (len > max) {
			max = len;
			copy(longest, line);
	}
	if (max > 0)
		printf("%s", longest);
	return 0;*/

}