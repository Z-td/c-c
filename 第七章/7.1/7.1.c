#include <stdio.h>
#include <ctype.h>

int main(int argc, char** argv)
{
	int (*pfun)(int);
	int ch;

	if (argc == 1)
	{
		if (argv[0][0] == 'u')
		{
			pfun = toupper;
		}
		else
		{
			pfun = tolower;
		}
		while ((ch = getchar()) != EOF)
		{
			ch = (*pfun)(ch);
			putchar(ch);
		}
	}
	else
	{
		printf("parameter error!\n");
		return -1;
	}
	return 0;
}