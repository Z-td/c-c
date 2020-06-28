#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void minprintf(char* fmt, ...);
int main(void)
{
	minprintf("aaa");//�˴�������Ӳ�������printf�����Ĳ���һ��
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

		for (int i = 0; i < 50 && !isalpha(*p); i++, p++) {//��%�Լ����ķ���ĸ�ַ�������������
			pfmt[i] = *p;
			pfmt[i++] = *p;//�����һ����ĸ�ַ�
			pfmt[i] = '\0';
		}
		//printf��������ֱ�ӽ���һ���ַ������������Ὣ�������滻Ϊ"����Ԫ��"��ʽ���Ӷ���ӡ

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
