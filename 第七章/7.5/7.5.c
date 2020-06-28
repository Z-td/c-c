#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define RAD_TO_DEG (180 / (4 * atan(1)))//将弧度转换为角度的公式，即1弧度 = 180 / π 度，其中π = 4 * atan(1)
#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define MAXVAR 26
#define NUMBERSIZE 100

int sp = 0;
char number[NUMBERSIZE];//储存输入的数字字符
double val[MAXVAL];
int index = 0;          //index为s字符数组的下标，是一个外部变量，可以跨函数使用

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
	double prev;        //记录最近打印的值
	char s[MAXOP];
	double var[MAXVAR];//包含26个单个英文字母的变量数组
	int print = 0;     //记录最近是否有打印的值
	int mask = 0;      //标记变量是否已赋值

	for (i = 0; i < MAXVAR; i++)//对每个变量的值进行初始化
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

		case 'd'://打印栈顶元素
			printf_stack_top();
			break;

		case 'f'://复制栈顶元素
			copy_stack_top();
			break;

		case 'j'://交换栈顶两个元素的值
			change_stack_top();
			break;

		case 'q'://清空栈
			empty_stack();
			break;

		case 's'://sin函数，注意sin、cos、tan接受的参数为弧度，不是角度
			push(sin((pop() / RAD_TO_DEG)));//将输入的角度转化为弧度
			break;

		case 'c'://cos函数
			push(cos((pop() / RAD_TO_DEG)));
			break;

		case 't'://tan函数
			op2 = pop();
			if (op2 != 90)
				push(tan((pop() / RAD_TO_DEG)));
			else
				printf("tan90 is invalid value\n");
			break;

		case 'e'://exp函数，返回e的指数幂
			push(exp(pop()));
			break;

		case 'p'://pow函数，返回参数1的参数2次幂，即假设pow(2, 3)，返回2^3的值
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
		val[sp++] = f;//按照从栈尾到栈顶的顺序依次压入数据
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];//按照栈顶到栈尾的顺序依次取出数据
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
			if (s[index] == ' ' || s[index] == '\t')//跳过空格和制表符
				index++;

			else if (!isdigit(s[index]) && s[index] != '.')//当遇到非数字字符和非.字符返回该字符
			{
				c = s[index];
				index++;//index递增，跳过该字符
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
				number[i] = '\0';//number数组此时存储一个数字的字符形式
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
	double temp = pop();//先弹出栈顶元素，将其拷贝给临时变量，将该变量压入两次，完成复制工作

	push(temp);
	push(temp);
	printf("Done!\n");
}

void change_stack_top(void)
{
	double temp1 = pop();//temp1是栈顶第一个元素
	double temp2 = pop();//temp2是栈顶第二个元素

	push(temp1);//temp1先压入，temp2后压入，temp1变成栈顶第二个元素，temp2变成栈顶第一个元素
	push(temp2);
}

void empty_stack(void)
{
	sp = 0;
}
