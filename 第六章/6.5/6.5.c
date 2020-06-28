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

	printf("�����봴���������\n");
	while(getword(name, 100) != EOF)
	{
		printf("����������ֵ��滻�ı�\n");
		getword(define, 100);
		if(install(name, define) == NULL)
			break;
		printf("������������\n");
	}

	printf("����������ҵ�����\n");
	while(getword(name, 100) != EOF)
	{
		if((np = lookup(name)) != NULL)
			printf("%s %s\n", np -> name, np -> defn);
		else
			printf("error\n");
	}

	printf("�������ɾ��������\n");
	while(getword(name, 100) != EOF)
	{
		if(undef(name))
			printf("ɾ���ɹ�\n");
		else
			printf("error\n");
	}

	printf("����������ҵ�����\n");
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

	if((np = lookup(name)) == NULL)//������������ƥ������֣����û��
	{
		np = (struct nlist *) malloc(sizeof(*np));
		
		if(np == NULL || (np -> name = sstrdup(name)) == NULL)
			return NULL;
		
		hashval = hash(name);
		np -> next = hashtab[hashval];//������ı�ͷ����hashtab[hashval]ָ�����ԭ����ı�ͷ
		hashtab[hashval] = np;//np���ڳ�Ϊ������ı�ͷ��hashtab[hashval]ָ��np
	}
	else
		free((void *) np -> defn);//�ͷ�ԭ�滻�ı�����Ŀռ�

	if((np -> defn = sstrdup(defn)) == NULL)//������������ƥ������֣�����ͨ�������Ϊdefn����ռ䲢��ֵ
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
