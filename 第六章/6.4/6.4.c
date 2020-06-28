#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

/*Author Stat:  founded 2017 11 26*/
static size_t word_count = 0;

struct line {
	char* word;
	size_t count;
	struct line* next;
};


int getword(char*, int);
struct line* additem(struct line*, char*);
void swapcontent(struct line*, struct line*);
void showitem(struct line*);
struct line* talloc(void);
char* strdup(char*);


int main(void)
{
	struct line* head;
	char word[MAXWORD];


	head = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			head = additem(head, word);
	printf("Total word: %lu\n", word_count);
	showitem(head);
	return 0;
}


int getword(char* word, int n)
{
	int c, getch(void);
	void ungetch(int);
	char* w = word;


	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --n > 0; w++)
		if (!isalpha(*w = getch())) {
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}


struct line* additem(struct line* p, char* w)
{
	if (p == NULL) {
		if ((p = talloc()) == NULL) {
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		if ((p->word = _strdup(w)) == NULL) {
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		p->count = 1;
		p->next = NULL;
		word_count++;
	}
	else if (strcmp(p->word, w) == 0)
		p->count++;
	else
		p->next = additem(p->next, w);
	if (p->next != NULL)
		swapcontent(p, p->next);
	return p;
}


void swapcontent(struct line* p, struct line* pn)
{
	size_t temp;
	char* temps;


	if (p->count < pn->count) {
		temp = p->count;
		p->count = pn->count;
		pn->count = temp;
		temps = p->word;
		p->word = pn->word;
		pn->word = temps;
	}


}


void showitem(struct line* p)
{
	if (p != NULL) {
		printf("%4lu %s\n", p->count, p->word);
		showitem(p->next);
		free(p->word);
		p->word = NULL;
		free(p);
		p = NULL;
	}
}


struct line* talloc(void)
{
	return (struct line*)malloc(sizeof(struct line));
}


char* strdup(char* s)
{
	char* p;


	if ((p = (char*)malloc(strlen(s) + 1)) != NULL)
		strcpy_s(' ',p, s);
	return p;
}


#define BUFSIZE 100


static char buf[BUFSIZE];
static int ps = 0;


int getch(void)
{
	return (ps > 0) ? buf[--ps] : getchar();
}

void ungetch(int c)
{
	if (ps > BUFSIZE)
		printf("stack too full!\n");
	else
		buf[ps++] = c;
}
