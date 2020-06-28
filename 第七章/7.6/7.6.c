#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 100
int main(void)
{
	FILE* fp1, * fp2;
	char filename1[MAXLEN], filename2[MAXLEN];
	char len1[MAXLEN], len2[MAXLEN];

	printf("请输入第一个待打开的文件名\n");
	scanf("%s", filename1);
	printf("请输入第二个待打开的文件名\n");
	scanf("%s", filename2);

	if ((fp1 = fopen(filename1, "r")) == NULL || (fp2 = fopen(filename2, "r")) == NULL)
	{
		fprintf(stderr, "error: can't open %s\n", (fp1 == NULL) ? filename1 : filename2);
		exit(1);
	}
	if (ferror(stdout))
	{
		fprintf(stderr, "error: writing stdout\n");
		exit(2);
	}

	while (1)
	{
		if (fgets(len1, MAXLEN, fp1) == NULL)
			strcpy(len1, "EOF");
		if (fgets(len2, MAXLEN, fp2) == NULL)
			strcpy(len2, "EOF");

		if (strcmp(len1, len2))
			break;
		if (!strcmp(len1, "EOF") && !strcmp(len2, "EOF"))
			break;
	}
	printf("file1: %s\n", len1);
	printf("file2: %s\n", len2);

	fclose(fp1);
	fclose(fp2);
	return 0;
}
