#include <stdio.h>
#include <ctype.h>

#define SIZE 10
#define BUFSIZE 10

int getch();
void ungetch(int c);
int getint(int* pn);

char buffer[BUFSIZE];
int bufp;

int main() {

	int n, array[SIZE];

	for (n = 0; n < SIZE; array[n++] = 0) //��ʼ�����飬������ֵ��Ϊ��
		;
	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) //���������е�������������ֱ�Ϊ��Ӧ��ֵ
		;
	for (n = 0; n < SIZE; printf("%d ", array[n++])) //��ӡֵ
		;

	return 1;
}

int getint(int* pn) {

	int c, temp, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-')
		return 0;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		if (!isdigit(temp = getch())) {
			ungetch(c);
			return 0;
		}
		else
			c = temp;
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);

	return c;
}

int getch() {

	return (bufp > 0) ? buffer[--bufp] : getchar();
}


void ungetch(int c) {

	if (bufp >= BUFSIZE)
		printf("oversized...\n");
	else
		buffer[bufp++] = c;

	return;

	
}