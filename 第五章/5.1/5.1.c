#include<stdio.h>
#include<ctype.h>

#define SIZE 10
#define BUFSIZE 10

int getch(void);
void  ungetch(int);
int getint(int* pn);

char buffer[BUFSIZE];
int bufp;

main() {


}



int getint(int* pn) {

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