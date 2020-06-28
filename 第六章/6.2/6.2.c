#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define BUFSIZE 100
#define MAXWORD 100

char buf[BUFSIZE];
int bufp = 0;

struct tree2 {            //第二层树，存储前6个字符相同的变量名
	char* s;
	int count;
	struct tree2* left;
	struct tree2* right;
};

struct tree1 {           //第一层树，存储前6个字符不同的变量名
	char* s;
	struct tree1* left;
	struct tree1* right;
	struct tree2* root;
};

int getword(char*, int);
struct tree1* addtree1(struct tree1* p, char* w, int n);
struct tree2* addtree2(struct tree2* p, char* w);
void treeprint2(struct tree2* p);
void treeprint1(struct tree1* p);
void* talloc(int n);
char* strdup(char* s, int n);
void freetree1(struct tree1* p);
void freetree2(struct tree2* p);


int main(int argc, char** argv)
{
	int n = 6;
	struct tree1* root = NULL;
	char word[MAXWORD];

	if (argc != 2)
		printf("parameters error!\n");
	else
		n = atoi(argv[1]);

	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree1(root, word, n);

	treeprint1(root);
	freetree1(root);   //释放malloc函数分配的空间
	return 0;
}

struct tree1* addtree1(struct tree1* p, char* w, int n)
{
	int cond;

	if (p == NULL)
	{
		p = (struct tree1*)talloc(1);
		p->s = _strdup(w, n);
		p->left = p->right = NULL;
		p->root = NULL;
		p->root = addtree2(p->root, w);//将首个单词存入二层树树根
	}

	else if ((cond = strncmp(w, p->s, n)) == 0)
		p->root = addtree2(p->root, w);

	else if (cond > 0)
		p->right = addtree1(p->right, w, n);

	else
		p->left = addtree1(p->left, w, n);
	return p;
}

struct tree2* addtree2(struct tree2* p, char* w)
{
	int cond;

	if (p == NULL)
	{
		p = (struct tree2*)talloc(2);
		p->s = _strdup(w, MAXWORD);
		p->count = 1;
		p->left = p->right = NULL;
	}

	else if ((cond = strcmp(w, p->s)) == 0)
		p->count++;

	else if (cond > 0)
		p->right = addtree2(p->right, w);

	else
		p->left = addtree2(p->left, w);
	return p;
}

void* talloc(int n)
{
	if (n == 1)
		return (struct tree1*)malloc(sizeof(struct tree1));//返回指向一层树一个节点的指针
	else
		return (struct tree2*)malloc(sizeof(struct tree2));//返回指向二层树一个节点的指针
}

char* strdup(char* s, int n)
{
	char* p;
	if (n == MAXWORD)
		p = (char*)malloc(strlen(s) + 1);
	else
		p = (char*)malloc(sizeof(char) * (n + 1));

	if (p != NULL)
	{
		*p = '\0';
		if (n == MAXWORD)
			strcpy_s(' ',p, s);
		else
			strncat_s(p, s, n,' ');
	}
	return p;
}

void treeprint1(struct tree1* p)
{
	if (p != NULL)
	{
		treeprint1(p->left);
		printf("%s: ", p->s);
		treeprint2(p->root);
		putchar('\n');
		treeprint1(p->right);
	}
}

void treeprint2(struct tree2* p)
{
	if (p != NULL)
	{
		treeprint2(p->left);
		printf("%s (%d)  ", p->s, p->count);
		treeprint2(p->right);
	}
}

void freetree1(struct tree1* p)
{
	struct tree1* pright;

	if (p != NULL)
	{
		pright = p->right;
		freetree1(p->left);
		freetree2(p->root);
		free(p);
		freetree1(pright);
	}
}

void freetree2(struct tree2* p)
{
	struct tree2* pright;

	if (p != NULL)
	{
		pright = p->right;
		freetree2(p->left);
		free(p);
		freetree2(pright);
	}
}

int getword(char* word, int lim)
{
	int c, prev, getch(void);
	void ungetch(int);
	char* w = word;

	while (isspace(c = getch()))
		;
	if (c != EOF)
		*w++ = c;
	if (!isalpha(c))
	{
		if (c == '\"')
		{
			while ((c = getch()) != '\"')
				;
		}
		else if (c == '/')
		{
			if ((c = getch()) == '*')
			{
				prev = ' ';
				while ((c = getch()) != EOF)//从遇到/*开始循环，直到EOF或者退出
				{
					if (c == '/' && prev == '*')
						break;
					prev = c;
				}
			}
			else if (c == '/')
			{
				while ((c = getch()) != '\n')
					;
			}
			else
				ungetch(c);
		}

		else
			*w = '\0';
		return c;
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
