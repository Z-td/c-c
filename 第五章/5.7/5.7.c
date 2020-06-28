#include<stdio.h>

#define maxline 100
//将输入的文本行存储到由main函数提供的一个数组中 
void Print(char save[][maxline], int len);
main()
{
	char save[maxline][maxline] = { 0 };
	int nlines;
	int readlines(char save[][maxline]);
	if ((nlines = readlines(save)) >= 0)
	{
		printf("save中的元素:\n");
		Print(save, nlines);
	}
	else
		printf("no lines");
}

void Print(char save[][maxline], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("第%d 行：%s\n", i, save[i]);
	}



}
int readlines(char save[][maxline])
{
	int nlines;
	int getline(char s[], int lim);
	int len;
	char line[100], * p = &save[0];

	nlines = 0;
	while ((len = getline(line, 100)) > 0) {
		strcpy(save + nlines++, line);
	}
	return nlines;
}
int getline(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;

	s[i] = '\0';
	return i;
}
