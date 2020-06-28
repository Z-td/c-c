#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAXWORD 100

/*Author Stat:  founded 2017 11 26*/
static int count_line = 1;


struct line {
	int line;
	struct line* next;
};


struct tnode {
	char* word;
	struct line* start;
	struct tnode* next;
};


struct tnode* addItem(struct tnode*, char*);
struct line* addlines(struct line*);
void showItem(struct tnode*);
void showLine(struct line*);
struct tnode* Ialloc(void);
struct line* Lalloc(void);
char* walloc(char*);
int getword(char*, int);
int Nonrealword(char*);


int main(void)
{
	struct tnode* head;
	char word[MAXWORD];


	head = NULL;
	while (getword(word, MAXWORD) != EOF)
		if (Nonrealword(word))
			if (isalpha(word[0]))
				head = addItem(head, word);
	printf("%33s\n\n", "Words  Line Number");
	showItem(head);


	return 0;
}


struct tnode* addItem(struct tnode* p, char* w)
{
	if (p == NULL) {
		if ((p = Ialloc()) == NULL) {
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		if ((p->word = walloc(w)) == NULL) {
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		if ((p->start = Lalloc()) == NULL) {
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		p->start->line = count_line;
		p->start->next = NULL;
		p->next = NULL;
	}
	else if (strcmp(p->word, w) == 0)
		p->start = addlines(p->start);
	else
		p->next = addItem(p->next, w);
	return p;
}


struct line* addlines(struct line* p)
{
	if (p == NULL) {
		if ((p = Lalloc()) == NULL) {
			printf("Out of memory!\n");
			exit(EXIT_FAILURE);
		}
		p->line = count_line;
		p->next = NULL;
	}
	else if (p->line == count_line)
		;
	else
		p->next = addlines(p->next);
	return p;
}


void showItem(struct tnode* p)
{
	if (p != NULL) {
		printf("%20s  ", p->word);
		showLine(p->start);
		printf("\n");
		showItem(p->next);
		free(p);
	}
}


void showLine(struct line* p)
{
	if (p != NULL) {
		printf("%d ", p->line);
		showLine(p->next);
		free(p);
	}
}


struct tnode* Ialloc(void)
{
	return (struct tnode*)malloc(sizeof(struct tnode));
}


struct line* Lalloc(void)
{
	return (struct line*)malloc(sizeof(struct line));
}


char* walloc(char* w)
{
	char* p;


	if ((p = (char*)malloc(strlen(w) + 1)) != NULL)
		strcpy_s( ' ',p, w);
	return p;
}
int getword(char* word, int max)
{
	int c, getch(void);
	void ungetch(int);
	char* w = word;


	while (isspace(c = getch()))
		if (c == '\n')
			count_line++;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --max; w++)
		if (!isalnum(*w = getch()))
			break;
	if (*w != '\'')
		ungetch(*w);
	else {
		w++;
		for (; --max; w++)
			if (!isalnum(*w = getch())) {
				ungetch(*w);
				break;
			}
	}
	*w = '\0';


	return word[0];
}


int Nonrealword(char* s)
{
	int i;
	static char* list[] = {
	   "a","an","and","be","but","by","he","I","is","off","on",
	   "she","so","the","they","you",NULL
	};


	i = 0;
	while (list[i]) {
		if (strcmp(list[i], s) == 0)
			return 0;
		i++;
	}
	return 1;
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