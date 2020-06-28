#include <stdio.h>
static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int* pmonth, int* pday);

int main(void)
{
	int year = 1946;
	int yearday = 0;
	int month;
	int day;
	int result;

	result = month_day(year, yearday, &month, &day);
	if (result == -1)
		printf("error!\n");
	else
		printf("%d年%d天是%d月%d日\n", year, yearday, month, day);

	month = 13;
	day = 25;
	result = day_of_year(year, month, day);
	if (result == -1)
		printf("error!\n");
	else
		printf("%d月%d日是%d年%d天\n", month, day, year, result);

	return 0;
}

int day_of_year(int year, int month, int day)
{
	int i, leap;

	if (month < 1 || month > 12 || day < 1 || day > 31)
		return -1;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
	for (i = 1; i < month; i++)
	{
		day += *(*(daytab + leap) + i);
	}
	return day;
}

int month_day(int year, int yearday, int* pmonth, int* pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (yearday < 1 || (!leap && yearday > 365) || (leap && yearday > 366))//闰年天数为366天
		return -1;

	for (i = 1; yearday > * (*(daytab + leap) + i); i++)
		yearday -= *(*(daytab + leap) + i);
	*pmonth = i;
	*pday = yearday;
}
