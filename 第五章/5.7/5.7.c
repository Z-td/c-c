#include<stdio.h>

#define maxline 100
//��������ı��д洢����main�����ṩ��һ�������� 
void Print(char save[][maxline], int len);
main()
{
	char save[maxline][maxline] = { 0 };
	int nlines;
	int readlines(char save[][maxline]);
	if ((nlines = readlines(save)) >= 0)
	{
		printf("save�е�Ԫ��:\n");
		Print(save, nlines);
	}
	else
		printf("no lines");
}

void Print(char save[][maxline], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("��%d �У�%s\n", i, save[i]);
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
