#include <stdio.h>

#define OCT 8
#define HEX 16
#define MAXLEN 10

int main(void)
{
	int n, ch, all;
	printf("��������ʲô���ƴ�ӡ��ͼ���ַ���oΪ�˽��ƣ�hΪʮ�����ƣ�:\n");

	ch = getchar();
	while (getchar() != '\n')
		continue;

	if (ch == 'o')
		n = OCT;
	else if (ch == 'h')
		n = HEX;
	else
		n = OCT;

	all = 0;
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 0 && ch <= 31 && ch != '\n')
		{
			if (all + 4 <= MAXLEN)
				all += 4;
			else
				putchar('\n');

			if (n == OCT)
				printf("o%-3o", ch);
			else
				printf("0x%-2x", ch);
		}
		else
		{
			putchar(ch);
			all++;
		}

		if (all % MAXLEN == 0)
		{
			putchar('\n');
			all = 0;
		}
	}
	return 0;
}
