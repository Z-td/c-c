#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLEN 100
#define LINE_PAGE 10

void print_page(FILE* fp, char* filename);

int main(int argc, char** argv)
{
	FILE* fp;

	if (argc < 2)
	{
		fprintf(stderr, "没有文件\n");
		exit(1);
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			if ((fp = fopen(argv[i], "r")) == NULL)
			{
				fprintf(stderr, "不能打开 %s\n", argv[i]);
				exit(1);
			}
			if (ferror(stdout))
			{
				fprintf(stderr, "error: writing stdout\n");
				exit(2);
			}
			print_page(fp, argv[i]);
			fclose(fp);
		}
	}
	return 0;
}

void print_page(FILE* fp, char* filename)
{
	char line[MAXLEN];
	int page = 0;
	long lineno = 0;
	int page_start = 1;

	while (fgets(line, MAXLEN, fp) != NULL)
	{
		if (page_start)
		{
			fprintf(stdout, "%40s page %d\n\n", filename, ++page);
			page_start = 0;
		}
		printf("%s", line);
		lineno++;
		if (lineno % LINE_PAGE == 0)
		{
			fprintf(stdout, "%80d page\n\f", page);
			page_start = 1;
		}
	}
	if (lineno % LINE_PAGE != 0)
		fprintf(stdout, "%80d page\n\f", page);
}
	