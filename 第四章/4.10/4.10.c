#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define RAD_TO_DEG (180 / (4 * atan(1)))
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXVAR 26
#define NUMBERSIZE 100

int sp = 0;
char number[NUMBERSIZE];
double val[MAXVAL];
int index = 0;          

int getline(char s[], int lim);
int getop(char[]);
void push(double);
double pop(void);
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

	while (getline(s, MAXOP) > 0)
	{
		while ((type = getop(s)) != '\0')
		{
			switch (type)
			{
			case NUMBER:
				push(atof(number));
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

			case 'd'://´òÓ¡Õ»
				printf_stack_top();
				break;

			case 'f'://¸´ÖÆÕ»
				copy_stack_top();
				break;

			case 'j'://½»»»Õ»
				change_stack_top();
				break;

			case 'q'://Çå¿ÕÕ»
				empty_stack();
				break;

			case 's'://sin
				push(sin((pop() / RAD_TO_DEG)));//½Ç¶È×ª»¡¶È
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

			case 'e':
				push(exp(pop()));
				break;

			case 'p':
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
		printf("¼ÌÐøÊäÈë\n");
		index = 0;
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
	int c;
	while (s[index] != '\0')
	{
		if (s[index] == ' ' || s[index] == '\t')
			index++;

		else if (!isdigit(s[index]) && s[index] != '.')
		{
			c = s[index];
			index++;
			return c;
		}

		else if (isdigit(s[index]))
		{
			int i = 0;
			while (isdigit(s[index]))
			{
				number[i++] = s[index];
				index++;
			}

			if (s[index] == '.')
			{
				number[i++] = s[index];
				index++;
				while (isdigit(s[index]))
				{
					number[i++] = s[index];
					index++;
				}
			}
			number[i] = '\0';
			return NUMBER;
		}
	}
	return s[index];//·µ»Ø¿Õ×Ö·û
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

int getline(char s[], int lim)
{
	int c, i;
	i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
	{
		s[i++] = c;
	}

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	return i;
}
