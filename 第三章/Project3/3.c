
#include<stdio.h>
#include<String.h>
#include<stdlib.h>
#include <iostream>
#define SIZE 100;
binsearch(int x, int v[], int n);
#define MAXLINE 5
#define MAXOP 100
#define NUMBER '0'

//int getop(char[]);
//void push(double);
//double pop(void);
//void printd(int n) {
//	if (n < 0) {
//		putchar('-');
//		n = -n;
//	}
//	if (n / 10)
//		printd(n / 10);
//	putchar(n % 10 + '0');
//}

void qsort(int v[],int left,int right ) {
	int i, last;
	void swap(int v[], int i, int j);
	if (left >= right)
		return;
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++);
	if (v[i] < v[left])
		swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last - 1);
	qsort(v, last + 1, right);

}
void swap(int v[], int i, int j) {

	int temp;
	temp = v[j];
	v[i] = v[j];
	v[j] = temp;
}
main() {
	///*printd(123);*/
	///*int search;
	//int result;
	//int number[size];

	//for (int i = 0; i < size ; i++)
	//	number[i] = i;

	//printf("输入查找数字\n");
	//while (scanf) {
	//}*/
	///*int c, i, nwhiter, nother, ndigit[10];
	//nwhiter = nother = 0;
	//for (i = 0; i < 10; i++)
	//	ndigit[i] = 0;
	//while ((c = getchar()) != eof) {
	//	switch (c)
	//	{
	//	case'0':
	//	case'1':
	//	case'2':
	//	case'3':
	//	case'4':
	//	case'5':
	//	case'6':
	//	case'7':
	//	case'8':
	//	case'9':
	//		ndigit[c - '0']++;
	//		break;
	//	case' ':
	//	case'\n':
	//	case'\t':
	//		nwhiter++;
	//		break;
	//	default:
	//		nother++;
	//		break;

	//}
	//}
	//printf("dis");
	//for (i = 0; i < 10; i++)
	//	printf("%d", ndigit[i]);
	//fprintf(",ws=%d\n,other%d", nwhiter, nother);
	//*/
	///*double sum, atof(char[]);
	//char line[maxline];
	//int getline(char line[], int max);
	//sum = 1;
	//while (getline(line, maxline) > 0)
	//	printf("\t%g\n", sum += atof(line));*/
	//	/*int type;
	//	double op2;
	//	char s[maxop];
	//	while ((type = getop(s)) != eof) {
	//		switch (type)
	//		{
	//		case number:
	//			push(atof(s));
	//			break;
	//		case '+':
	//			push(pop() + pop());
	//			break;
	//		case '-':
	//			op2 = pop();
	//			push(pop() - op2);
	//			break;
	//		case '*':
	//			push(pop() * pop());
	//			break;
	//		case '/':
	//			op2=pop();
	//			push(pop() / pop());
	//			break;
	//		default:
	//			break;
	//		}
	//	}*/
	//	//int  a, b, d;
	//	//char c;
	//	///*scanf_s("%lf%c%lf", &a, &c, &b);*/
	//	//scanf_s("%d%c%d",&a, &c,&b);
	//	//printf("%d%c%d",a, c,b);
	//	/*switch (c)
	//	{
	//	case '+': d = a + b; printf("计算结果为：%lf", d); break;
	//	case '-': d = a - b; printf("计算结果为：%lf", d); break;
	//	case '*': d = a * b; printf("计算结果为：%lf", d); break;
	//	case '/': d = a / b; printf("计算结果为：%lf", d); break;
	//	default:printf("有误，请重新输入");
	//	}*/
	return 0;

}
































#include<stdio.h>
int main()
{
	return 0;
}
void escape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch (t[i]) {
		case '\n':
		{s[j++] = '\\'; s[j++] = 'n'; break; }
		case '\t':
		{s[j++] = '\\'; s[j++] = 't'; break; }
		default:
		{s[j++] = t[i]; break; }
		}
	}
	s[j] = '\0';

}
void unsecape(char s[], char t[])
{
	int i, j;
	for (i = j = 0; t[i] != '\0'; i++)
	{
		switch (t[i]) {
		case '\\':
			switch (t[++i]) {
			case 'n':
				s[j++] = '\n'; break;
			case 't':
				s[j++] = '\t'; break;
			default:
				s[j++] = '\\'; s[j++] = t[i]; break;
			}
		default:
			s[j++] = t[i]; break;
		}
	}
	s[j] = '\0';
}



















