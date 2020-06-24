#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define RAD_TO_DEG (180 / (4 * atan(1)))//弧度转角度
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define MAXVAR 26

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int getop(char[]);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void printf_stack_top(void);
void copy_stack_top(void);
void change_stack_top(void);
void empty_stack(void);

int main(void)
{
	int type, i;
	double op2;
	double prev;        
	char s[MAXOP];
	double var[MAXVAR];
	int print = 0;     
	int mask = 0;      

	for (i = 0; i < MAXVAR; i++)
		var[i] = 0.0;

	while ((type = getop(s)) != EOF)
	{
		switch (type)
		{
		case NUMBER:
			push(atof(s));
			break;

		case '+':
			push(pop() + pop());
			break;

		case '*':
			push(pop() * pop());
			break;

		case '-':
			op2 = pop();
			push(pop() - op2);
			break;

		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;

		case '%':
			op2 = pop();
			if (op2 != 0.0)
				push((int)pop() % (int)op2);
			else
				printf("error: zero divisor\n");
			break;

		case 'd'://打印栈顶
			printf_stack_top();
			break;

		case 'f'://复制栈顶
			copy_stack_top();
			break;

		case 'j'://交换栈顶
			change_stack_top();
			break;

		case 'q'://清空栈
			empty_stack();
			break;

		case 's'://sin
			push(sin((pop() / RAD_TO_DEG)));//角度转弧度
			break;

		case 'c'://cos
			push(cos((pop() / RAD_TO_DEG)));
			break;

		case 't'://tan
			op2 = pop();
			if (op2 != 90)
				push(tan((pop() / RAD_TO_DEG)));
			else
				printf("tan90 is invalid value\n");
			break;

		case 'e'://exp
			push(exp(pop()));
			break;

		case 'p'://pow
			op2 = pop();
			push(pow(pop(), op2));
			break;

		case 'v':
			if (print)
				printf("The most recently printed value is %.8g\n", prev);
			else
				printf("No recently printed values!\n");
			break;

		case '\n':
			prev = pop();
			print = 1;
			printf("\t%.8g\n", prev);
			break;

		default:
			if (type >= 'A' && type <= 'Z')
			{
				if (mask == 0)
				{
					var[type - 'A'] = pop();
					mask = 1;
				}
				else
					push(var[type - 'A']);
			}
			
			
			else
				printf("error: unkown command %s\n", s);
			break;
		}
	}
	return 0;
}

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void printf_stack_top(void)
{
	if (sp > 0)
		printf("top of stack: %8g\n", val[sp - 1]);
	else
		printf("stack is empty\n");
}

void copy_stack_top(void)
{
	double temp = pop();

	push(temp);
	push(temp);
	printf("Done!\n");
}

void change_stack_top(void)
{
	double temp1 = pop();
	double temp2 = pop();

	push(temp1);
	push(temp2);
}

void empty_stack(void)
{
	sp = 0;
}
