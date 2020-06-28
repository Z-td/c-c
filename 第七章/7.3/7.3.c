#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minprintf(char* fmt, ...);
int main(void)
{
	minprintf("aaa");//此处自行添加参数，和printf函数的参数一样
	return 0;
}

void minprintf(char* fmt, ...)
{
	va_list ap;
	char pfmt[50];
	char* p, * sval;
	int ival;
	double dval;
	unsigned uval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}

		for (int i = 0; i < 50 && !isalpha(*p); i++, p++) {//将%以及其后的非字母字符储存在数组中
			pfmt[i] = *p;
			pfmt[i++] = *p;//储存第一个字母字符
			pfmt[i] = '\0';
		}
		//printf函数可以直接接受一个字符数组名，它会将数组名替换为"数组元素"形式，从而打印

		switch (*p)
		{
		case 'i':
		case 'd':
		case 'c':
			ival = va_arg(ap, int);
			printf(pfmt, ival);
			break;

		case 'x':
		case 'X':
		case 'u':
		case 'o':
			uval = va_arg(ap, unsigned);
			printf(pfmt, uval);
			break;

		case 'f':
		case 'e':
		case 'E':
		case 'g':
		case 'G':
			dval = va_arg(ap, double);
			printf(pfmt, dval);
			break;

		case 's':
		case 'p':
			sval = va_arg(ap, char*);
			printf(pfmt, sval);
			break;

		default:
			printf(pfmt);
			break;
		}
	}
	va_end(ap);
}
