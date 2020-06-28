#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

struct nlist {
	struct nlist *next;
	char *name;
	char *defn;
};
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s);
struct nlist *lookup(char *s);
struct nlist *install(char *name, char *defn);
int undef(char *name);
char *sstrdup(char *s);
int getword(char *word, int lim);
int getch(void);
void ungetch(int c);

int main(void)
{
	char name[100], define[100];
	struct nlist *np;

	printf("请输入创建表的名字\n");
	while(getword(name, 100) != EOF)
	{
		printf("请输入该名字的替换文本\n");
		getword(define, 100);
		if(install(name, define) == NULL)
			break;
		printf("继续输入名字\n");
	}

	printf("请输入待查找的名字\n");
	while(getword(name, 100) != EOF)
	{
		if((np = lookup(name)) != NULL)
			printf("%s %s\n", np -> name, np -> defn);
		else
			printf("error\n");
	}

	printf("请输入待删除的名称\n");
	while(getword(name, 100) != EOF)
	{
		if(undef(name))
			printf("删除成功\n");
		else
			printf("error\n");
	}

	printf("请输入待查找的名字\n");
	while(getword(name, 100) != EOF)
	{
		if((np = lookup(name)) != NULL)
			printf("%s %s\n", np -> name, np -> defn);
		else
			printf("error\n");
	}

	return 0;
}

unsigned hash(char *s)
{
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
	struct nlist *np;

	for(np = hashtab[hash(s)]; np != NULL; np = np -> next)
		if(strcmp(s, np -> name) == 0)
			return np;

	return NULL;
}

struct nlist *install(char *name, char *defn)
{
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL)//查找链表有无匹配的名字，如果没有
	{
		np = (struct nlist *) malloc(sizeof(*np));
		
		if(np == NULL || (np -> name = sstrdup(name)) == NULL)
			return NULL;
		
		hashval = hash(name);
		np -> next = hashtab[hashval];//从链表的表头添加项，hashtab[hashval]指向的是原链表的表头
		hashtab[hashval] = np;//np现在成为新链表的表头，hashtab[hashval]指向np
	}
	else
		free((void *) np -> defn);//释放原替换文本分配的空间

	if((np -> defn = sstrdup(defn)) == NULL)//不管链表有无匹配的名字，都将通过此语句为defn分配空间并赋值
		return NULL;

	return np;
}

int undef(char *name)
{
	struct nlist *np1, *np2;

	for(np1 = hashtab[hash(name)], np2 = NULL; np1 != NULL; np2 = np1, np1 = np1 -> next)
		if(!strcmp(name, np1 -> name))
		{
			if(np2 == NULL)
				hashtab[hash(name)] = np1 -> next;
			else
				np2 -> next = np1 -> next;
			free(np1 -> name);	
	        free(np1 -> defn);
	        free(np1);
	        return 1;
		}
	return 0;
}

char *sstrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s) + 1);

	if(p != NULL)
		strcpy_s(' ',p, s);
	return p;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalnum(c))
	{
		*w = '\0';
		return c;
	}
	for(; --lim > 0; w++)
		if(!isalnum(*w = getch()))
		{
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("error: too many parameters\n");
	else
		buf[bufp++] = c;
}
