#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 1000

int main(int argc, char** argv)
{
	char line[MAXLEN];
	long lineno = 0;//记录行号
	FILE* fp;

	if (argc < 2)
		fprintf(stderr, "参数太少\n");
	else if (argc == 2)
	{
		while (fgets(line, MAXLEN, stdin) != NULL)
		{
			lineno++;
			if (strstr(line, argv[1]) != NULL)
				fprintf(stdout, "%ld: %s", lineno, line);
		}
	}
	else
	{
		for (int i = 2; i < argc; i++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "error: can't open %s\n", argv[i]);
				exit(1);
			}
			if (ferror(stdout))
			{
				fprintf(stderr, "error: writing stdout\n");
				exit(2);
			}
			lineno = 0;
			fprintf(stdout, "file: %s\n", argv[i]);
			while (fgets(line, MAXLEN, fp) != NULL)
			{
				lineno++;
				if (strstr(line, argv[1]) != NULL)
					fprintf(stdout, "%ld: %s", lineno, line);
			}
			putchar('\n');
			fclose(fp);
		}
	}
	return 0;
}
