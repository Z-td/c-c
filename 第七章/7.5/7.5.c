#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define RAD_TO_DEG (180 / (4 * atan(1)))//������ת��Ϊ�ǶȵĹ�ʽ����1���� = 180 / �� �ȣ����Ц� = 4 * atan(1)
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXVAR 26
#define NUMBERSIZE 100

int sp = 0;
char number[NUMBERSIZE];//��������������ַ�
double val[MAXVAL];
int index = 0;          //indexΪs�ַ�������±꣬��һ���ⲿ���������Կ纯��ʹ��

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
	double prev;        //��¼�����ӡ��ֵ
	char s[MAXOP];
	double var[MAXVAR];//����26������Ӣ����ĸ�ı�������
	int print = 0;     //��¼����Ƿ��д�ӡ��ֵ
	int mask = 0;      //��Ǳ����Ƿ��Ѹ�ֵ

	for (i = 0; i < MAXVAR; i++)//��ÿ��������ֵ���г�ʼ��
		var[i] = 0.0;

	while ((type = getop(s)) != EOF)
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

		case 'd'://��ӡջ��Ԫ��
			printf_stack_top();
			break;

		case 'f'://����ջ��Ԫ��
			copy_stack_top();
			break;

		case 'j'://����ջ������Ԫ�ص�ֵ
			change_stack_top();
			break;

		case 'q'://���ջ
			empty_stack();
			break;

		case 's'://sin������ע��sin��cos��tan���ܵĲ���Ϊ���ȣ����ǽǶ�
			push(sin((pop() / RAD_TO_DEG)));//������ĽǶ�ת��Ϊ����
			break;

		case 'c'://cos����
			push(cos((pop() / RAD_TO_DEG)));
			break;

		case 't'://tan����
			op2 = pop();
			if (op2 != 90)
				push(tan((pop() / RAD_TO_DEG)));
			else
				printf("tan90 is invalid value\n");
			break;

		case 'e'://exp����������e��ָ����
			push(exp(pop()));
			break;

		case 'p'://pow���������ز���1�Ĳ���2���ݣ�������pow(2, 3)������2^3��ֵ
			op2 = pop();
			push(pow(pop(), op2));
			break;

		case 'v':
			if (print)
				printf("The most recently printed value is %.8g\n", prev);
			else
				printf("No recently printed values!\n");
			break;

		case '=':
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
		val[sp++] = f;//���մ�ջβ��ջ����˳������ѹ������
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];//����ջ����ջβ��˳������ȡ������
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[])
{
	int c;
	index = 0;
	if (scanf_s("%s", s) != EOF)
	{
		while (s[index] != '\0')
		{
			if (s[index] == ' ' || s[index] == '\t')//�����ո���Ʊ��
				index++;

			else if (!isdigit(s[index]) && s[index] != '.')//�������������ַ��ͷ�.�ַ����ظ��ַ�
			{
				c = s[index];
				index++;//index�������������ַ�
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
				number[i] = '\0';//number�����ʱ�洢һ�����ֵ��ַ���ʽ
				return NUMBER;
			}
		}
	}
	return EOF;
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
	double temp = pop();//�ȵ���ջ��Ԫ�أ����俽������ʱ���������ñ���ѹ�����Σ���ɸ��ƹ���

	push(temp);
	push(temp);
	printf("Done!\n");
}

void change_stack_top(void)
{
	double temp1 = pop();//temp1��ջ����һ��Ԫ��
	double temp2 = pop();//temp2��ջ���ڶ���Ԫ��

	push(temp1);//temp1��ѹ�룬temp2��ѹ�룬temp1���ջ���ڶ���Ԫ�أ�temp2���ջ����һ��Ԫ��
	push(temp2);
}

void empty_stack(void)
{
	sp = 0;
}
