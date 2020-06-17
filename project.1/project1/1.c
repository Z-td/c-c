#include <stdio.h>
#define MAXLINE 1000
#define IN 1
#define OUT 0
int getline(char line[], int maxline);
void copy(char to[], char from[]);

	//printf("1.1：\n");
	//printf("hello,world\n");

	//printf("1.2：\n");
	//printf("hello,world\c\n");

	//printf("1.3：\n");
	//float  fahr, ceksius;
	//int lower, upper, step;
	//lower = 0; /*下限*/
	//upper = 300; /*上限*/
	//step = 20;/*步长*/
	//fahr = lower;
	//printf("华氏度转摄氏度\n");
	//while (fahr <= upper)
	//{
	//	ceksius = (5.0 / 9.0) * (fahr - 32.0);
	//	printf("%3.0f %6.1f\n", fahr, ceksius);
	//	fahr = fahr + step;
	//}

	//printf("1.4：\n");
	//printf("摄氏度转华氏度\n");
	//fahr = 0;
	//while (fahr <= upper)
	//{
	//	ceksius = fahr * (9.0 / 5.0) + 32;
	//	printf("%3.0f %3.1f\n", fahr, ceksius);
	//	fahr = fahr + step;
	//}

	//printf("1.5\n");
	//int newfahr;
	//for (newfahr = 300; newfahr >= 0; newfahr = newfahr - 20)
	//	printf("%3d %6.1f\n ", newfahr, (5.0 / 9.0) * (newfahr - 32));

	//printf("1.6\n");
	//int a;
	//a = getchar() != EOF;
	//printf("%d", a);

	//printf("\n1.7\n");
	//printf("%d", EOF );

	//printf("\n1.8\n");
	//int b,c;
	//b = 0;
	//while ((c = getchar()) != EOF)
	//	if (c == '\n' || c == ' ' || c == '\t')
	//		++b;
	//printf("%d\n",b);

	//printf("1.9\n");
	//char d;
	//int e = 0;
	//while ((d = getchar()) != EOF)
	//{
	//	if (d == ' ') {
	//		if (e == 0)
	//		{
	//			putchar(d);
	//			e = 1;
	//		}
	//		else
	//		{
	//			putchar(d);
	//			e = 0;
	//		}
	//	}
	//}

	//printf("\n1.10\n");
	//char f;
	//f = "123\b159\t158\b";
	//while ((f = getchar()) != EOF)
	//{
	//	if (f == '\t')
	//		printf("\t");

	//	if (f == '\b')
	//		printf("\b");

	//	if (f == '\\')
	//		printf("\\");

	//	if (f != '\t' && f !='\b' &&  f !='\\')
	//				putchar(f);
	//	
	//}
	//printf("\n1.11\n");


	//printf("\n1.12\n");
	//char g;
	//int n1, nw, nc, state;

	//state = OUT;
	//n1 = nw = nc = 0;

	//while ((g = getchar()) != EOF)
	//{
	//	++nc;
	//	if (g == '\n')
	//		++n1;

	//	if (g == ' ' || g == '\n' || g == '\t')
	//	{
	//		state = OUT;
	//	}
	//	else if (state == OUT)
	//	{
	//		state = IN;
	//		++nw;
	//		putchar('\n');
	//		putchar(g);
	//	}
	//	else if (state == IN)
	//	{
	//		putchar(g);
	//	}

	//}

	//printf("%d %d %d \n", n1, nw, nc);
	//
	//printf("\n1.13\n");




	///*int len;
	//int max;
	//char line[MAXLINE];
	//char longest[MAXLINE];

	//max = 0;
	//while ((len - getline(line,MAXLINE)) > 0)
	//	if (len > max) {
	//		max = len;
	//		copy(longest, line);
	//}
	//if (max > 0)
	//	printf("%s", longest);
	//return 0;*/

