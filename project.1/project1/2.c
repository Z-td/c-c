#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<String.h>
#include<ctype.h>
#include<math.h>
#define MAXLINE 1000
#define limit 100
#define MAXLEN 20


void squeeze(char s1[], char s2[])
{
	int i, j, k;
	for (i = k = 0; s1[i] != '\0'; i++)
	{
		for (j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;
		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
	printf("s1中去除与s2相同的符号后剩下的是%s\n", s1);
}

main(){
	
	//2.1
	printf("schar %d %d\n", SCHAR_MAX,SCHAR_MIN);
	printf("sshort %d %d\n", SHRT_MAX, SHRT_MIN);
	printf("sint %d %d\n", INT_MAX, INT_MIN);
	printf("slong %d %d\n", LONG_MAX, LONG_MIN);

	printf("ulong %d %u\n", 0, ULONG_MAX);
	printf("ushort %d %d\n", 0, USHRT_MAX);
	printf("uchar %d %d\n", 0, UCHAR_MAX);
	printf("uint %d %u\n", 0, UINT_MAX);


	//2.2
	/*int lim = MAXLINE;
	printf("%d",lim);

	int i = 0, c;
	char s[limit];
	while ( i < limit - 1) {
		c = getchar();
		if (c = '\n')
			break;
		if (c = EOF)
			break;	
		s[i] = c;
	}*/
	/*for ( i = 0; i < limit-1 && (c=getchar())!='\n' && c!= EOF; i++)
	{
		s[i] = c;
	}*/
	//2.3
	/*char s[20];
	char c;
	int i = 0;
	while ((c=getchar())!=EOF&&(c!=' ')&&(c!='\n'))
	{
		s[i++] = c;
	}
	s[i] = ' ';
	printf("%d\n", htoi(s));*/

	//2.4

	char s1[20] = "hello ngf";
	char s2[20] = "hi ngf";
	squeeze(s1, s2);
	//2.5
	
	return 0;
}



//2.3
int htoi(char s[]) {
	int d = 0, e = 0, f;
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		d = 2;
	}
	int j = 0;
	while (s[j++] !=' '){
	}
	f = j - 2;
	for (int i = 1; f >= d; i = i * 16) {
		if (s[f] >= '0' && s[f] <='9') {
			e = e + (s[f] - '0') * i;
		}else if (s[f] >= 'a' && s[f] <= 'f') {
			e = e + (s[f] - 'a'+10) * i;
		}else if(s[f] >= 'A' && s[f] <= 'F'){
			e = e + (s[f] - 'A'+10) * i;
		}
		f--;
	}
	return e;
}
//2.4
