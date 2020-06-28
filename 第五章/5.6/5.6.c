#include <stdio.h>
#include <string.h>
#include <ctype.h>
main() {


}
int getline(char* s, int lim)
{
	int c;
	char* start = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
	{
		*s++ = c;
	}

	if (c == '\n')
		*s++ = c;

	*s = '\0';
	return (s - start);
}

int atoi(char* s)
{
	int n, sign;
	while (isspace(*s))
		s++;
	sign = (*s != '-' && *s != '+') ? 1 : ((*s++ == '+') ? 1 : -1);

	for (n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');
	return n * sign;
}

void itoa(int n, char* s)
{
	unsigned int u;
	char* start = s;
	u = (n < 0) ? -n : n;

	do {
		*s++ = (u % 10) + '0';
	} while ((u /= 10) > 0);

	if (n < 0)
		*s++ = '-';

	*s = '\0';
	reverse(start);
}

int  reverse(char* s)
{
	int temp;
	char* end = s;
	while (*end)
		end++;
	end--;
	for (; end - s > 0; end--, s++)
	{
		temp = *s;
		*s = *end;
		*end = temp;
	}
}

void itob(int n, char* s, int b)
{
	unsigned int u;
	char* start = s;
	u = (n < 0) ? -n : n;

	do
	{
		if (u % b > 9)
			*s++ = (u % b) - 10 + 'A';
		else
			*s++ = (u % b) + '0';
	} while ((u /= b) > 0);

	if (n < 0)
		*s++ = '-';

	*s = '\0';
	reverse(start);
}

double atof(char s[])
{
	double val;
	double power = 1.0;
	double sign;
	int mask;      //标记e后面的符号
	int power_e;   //记录指数大小
	double result; //结果值

	while (isspace(*s))
		s++;

	sign = (*s != '+' && *s != '-') ? 1 : ((*s++ == '+') ? 1 : -1);

	for (val = 0; isdigit(*s); s++)
		val = 10.0 * val + (*s - '0');

	if (*s == '.')
	{
		s++;
		for (; isdigit(*s); s++)
		{
			val = 10.0 * val + (*s - '0');
			power *= 10.0;
		}
	}

	result = sign * val / power;
	if (*s == 'e' || *s == 'E')
	{
		s++;
		if (*s == '-')
			mask = 1;
		else if (*s == '+' || isdigit(*s))
			mask = 0;
		else
			return result;

		if (*s == '-' || *s == '+')
			s++;

		for (power_e = 0; isdigit(*s); s++)
			power_e = 10 * power_e + (*s - '0');

		if (mask)//e后面符号为-时，表示除以power_e个10.0
		{
			while (power_e > 0)
			{
				result /= 10.0;
				power_e--;
			}
			return result;
		}
		else//e后面符号为+或没有符号时，表示乘以power_e个10.0
		{
			while (power_e > 0)
			{
				result *= 10.0;
				power_e--;
			}
			return result;
		}
	}
	else//数字后面没有e或E
		return result;
}

int strindex(char* s, char* t)
{
	int length_s = strlen(s) - 1;
	int length_t = strlen(t) - 1;
	char* end_s = s + length_s - 1;
	char* end_t = t + length_t - 1;
	char* p, * q;

	for (; end_s >= s; end_s--)
	{
		for (p = end_s, q = end_t; (q >= t) && (*p == *q); p--, q--)
			;
		if (q < t)
			return (p - s + 2);//返回字符出现在字符串中的实际位置
	}
	return -1;
}

int getop(char s[])
{
	int i, c;
	while ((*s = c = getch())== ' ' || c == '\t')
	;
	*(s++) = '\0';
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(*s++ = c = getch()))
			;

	if (c == '.')
		while (isdigit(*s++ = c = getch()))
			;

	*s = '\0';
	if (c != EOF)
		ungetch(c);
	return 1;
}
