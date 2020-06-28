#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HASHSIZE 101
#define BUFSIZE 100
#define MAXWORD 100



char buf[BUFSIZE];
int bufp = 0;
char name[MAXWORD];
char defn[MAXWORD];

struct nlist {
	struct nlist* next;
	char* name;
	char* defn;
};

static struct nlist* hashtab[HASHSIZE];

unsigned hash(char* s);
struct nlist* lookup(char* s);
struct nlist* install(char* name, char* defn);
int undef(char* name);
char* _strdup(char* s);
int getword(char* word, int lim);
int getch(void);
void ungetch(int c);
void skipblanks(void);



int main()
{
	char word[MAXWORD];
	struct nlist* np;

	while (getword(word, MAXWORD) != EOF)
	{
		if (isalpha(word[0]) || word[0] == '_')
		{
			if ((np = lookup(word)) != NULL)
				printf("%s", np->defn);
			else
				printf("%s", word);
		}
		else
			printf("%s", word);
	}

	return 0;
}

unsigned hash(char* s)
{
	unsigned hashval;

	for (hashval = 0; *s != '\0'; s++)
		hashval = *s + 31 * hashval;
	return hashval % HASHSIZE;
}

struct nlist* lookup(char* s)
{
	struct nlist* np;

	for (np = hashtab[hash(s)]; np != NULL; np = np->next)
		if (strcmp(s, np->name) == 0)
			return np;

	return NULL;
}

struct nlist* install(char* name, char* defn)
{
	struct nlist* np;
	unsigned hashval;

	if ((np = lookup(name)) == NULL)//查找链表有无匹配的名字，如果没有
	{
		np = (struct nlist*)malloc(sizeof(*np));

		if (np == NULL || (np->name = _strdup(name)) == NULL)
			return NULL;

		hashval = hash(name);
		np->next = hashtab[hashval];//从链表的表头添加项，hashtab[hashval]指向的是原链表的表头
		hashtab[hashval] = np;//np现在成为新链表的表头，hashtab[hashval]指向np
	}
	else
		free((void*)np->defn);//释放原替换文本分配的空间

	if ((np->defn = _strdup(defn)) == NULL)//不管链表有无匹配的名字，都将通过此语句为defn分配空间并赋值
		return NULL;

	return np;
}

int undef(char* name)
{
	struct nlist* np1, * np2;

	for (np1 = hashtab[hash(name)], np2 = NULL; np1 != NULL; np2 = np1, np1 = np1->next)
		if (!strcmp(name, np1->name))
		{
			if (np2 == NULL)
				hashtab[hash(name)] = np1->next;
			else
				np2->next = np1->next;
			free(np1->name);
			free(np1->defn);
			free(np1);
			return 1;
		}
	return 0;
}

char* strdup(char* s)
{
	char* p;

	p = (char*)malloc(strlen(s) + 1);

	if (p != NULL)
		strcpy(p, s);
	return p;
}

int getword(char* word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char* w = word;
	struct nlist* np;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalnum(c))
	{
		if (c == '#')
		{
			w = word;
			for (; --lim > 0 && isalpha(c = getch()); *w++ = c)
				;
			*w = '\0';
			skipblanks();

			if (!strcmp(word, "define"))//处理#define命令
			{
				for (int i = 0; i < MAXWORD && (isalnum(c = getch()) || c == '_'); i++)
				{
					name[i] = c;
					if (isdigit(name[0]))//排除首字符为字母的情况
						printf("error: the first character cannot be a number\n");
					name[i] = '\0';
				}
				

				skipblanks();
				for (int i = 0; i < MAXWORD; i++)
				{
					defn[i] = getch();
					if (defn[i] == '\n' && defn[i - 1] != '\\')//允许使用'\'字符换行的情况
						break;
					defn[i] = '\0';
				}
				
				install(name, defn);
				word[0] = '\0';
			}

			else if (!strcmp(word, "undef"))//处理#undef
			{
				for (int i = 0; i < MAXWORD && (isalnum(c = getch()) || c == '_'); i++)
				{
					name[i] = c;
					if (isdigit(name[0]))
						printf("error: the first character cannot be a number\n");
					name[i] = '\0';
				}
				
				if (!undef(name))
					printf("error: The name was not found");
				word[0] = '\0';
			}

			else//处理#加宏名的情况，使用""包裹替换文本取代
			{
				if ((np = lookup(word)) != NULL)
				{
					strcpy(word, "\"");
					strcat(word, np->defn);
					strcat(word, "\"");
				}
				else
					printf("error: invalid instruction\n");
			}

			return 0;
		}
		else
		{
			*w = '\0';
			return c;
		}
	}
	for (; --lim > 0; w++)
		if (!isalnum(*w = getch()))
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
	if (bufp >= BUFSIZE)
		printf("error: too many parameters\n");
	else
		buf[bufp++] = c;
}

void skipblanks(void)
{
	int c;
	while ((c = getch()) == ' ' || c == '\t')
		;
	ungetch(c);
}
