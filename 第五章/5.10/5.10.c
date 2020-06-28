#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define RAD_TO_DEG (180 / (4 * atan(1)))//������ת��Ϊ�ǶȵĹ�ʽ����1���� = 180 / �� �ȣ����Ц� = 4 * atan(1)
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXVAR 26

int sp = 0;
double val[MAXVAL];

int getop(char s[], char t[]);
void push(double);
double pop(void);
void printf_stack_top(void);
void copy_stack_top(void);
void change_stack_top(void);
void empty_stack(void);

int main(int argc, char** argv)
{
	int type, i;
	double op2;
	double prev;        //��¼�����ӡ��ֵ
	char s[MAXOP];
	double var[MAXVAR];//����26������Ӣ����ĸ�ı�������
	int print = 0;     //��¼����Ƿ��д�ӡ��ֵ
	int mask = 0;      //��Ǳ����Ƿ��Ѹ�ֵ

	for (i = 0; i < MAXVAR; i++)//��ÿ��������ֵ���г�ʼ��
		var[i] = 0.0;

	if (argc < 2)
	{
		printf("error: too few parameters\n");
		return -1;
	}

	while (argc-- > 0)//�˳�������Ҫ��һ������������������Ĳ���Ϊ4��(����������)��������Ҫ��ѭ������4��
	//ǰ���δ��������г�������������������������Ĵ���Ҫ������Ϊ������ֹ��־�Ļ��з�
	{
		if (argc == 0)//��argc==0�ǣ�type='\n'�����������
			type = '\n';
		else
			type = getop(s, *++argv);
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

		case 'd':
			printf_stack_top();
			break;

		case 'f':
			copy_stack_top();
			break;

		case 'j':
			change_stack_top();
			break;

		case 'q':
			empty_stack();
			break;

		case 's':
			push(sin((pop() / RAD_TO_DEG)));
			break;

		case 'c':
			push(cos((pop() / RAD_TO_DEG)));
			break;

		case 't':
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

int getop(char s[], char t[])
{
	int i, c;
	*s++ = c = *t++;//����Ҫ�����ո��

	if (!isdigit(c) && c != '.')
		return c;

	if (isdigit(c))
		while (isdigit(*s++ = c = *t++))
			;

	if (c == '.')
		while (isdigit(*s++ = c = *t++))
			;
	if (c == '\0')
	{
		*s = '\0';
		return NUMBER;
	}
	return c;
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
