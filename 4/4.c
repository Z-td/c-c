#include<stdio.h>
#include <stdlib.h>
#include<sys.h>
#define forever for( ; ;)
#define dqrint(expr) printf(#expr"=%g\n",expr)


ssize_t read(int fd, void* buf, size_t count);
//void swap(int *x,int *y){
//	int temp;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//	printf("%d%d", &x, &y);
//
//}


//void qsort(int v[], int left, int right) {s
//	int i, last;
//	void swap(int v[], int i, int j);
//	if (left >= right)
//		return;
//	swap(v, left, (left + right) / 2);
//	last = left;
//	for (i = left + 1; i <= right; i++);
//	if (v[i] < v[left])
//		swap(v, ++last, i);
//	swap(v, left, last);
//	qsort(v, left, last - 1);
//	qsort(v, last + 1, right);
//
//}
//void swap(int v[], int i, int j) {
//
//	int temp;
//	temp = v[j];
//	v[i] = v[j];
//	v[j] = temp;
//}
//int strlen(char *s)
//{
//	
//	char* p = s;
//	printf("%d\n", p);
//	while (*p != '\0')
//		p++;
//	printf("%d", p-s );
//}


//static char daytabb[2][13] = {
//	{0,31,28,31,30,31,30,31,31,30,31,30,31},
//	{0,31,29,31,30,31,30,31,31,30,31,30,31}
//};
//int day_of(int year,int month,int day) {
//	int i, leep;
//	leep = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//	for (i = 1; i < month; i++)
//		day += daytabb[leep][i];
//	return day;
//
//}
//int month_day(int year, int yearday, int *pmonth, int *pday) {
//	int i, leep;
//	leep = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//	for (i = 1;yearday>daytabb[leep][i]; i++)
//		yearday -= daytabb[leep][i];
//	*pmonth = i;
//	*pday = yearday;
//
//}
//char month_name(int n)
//{
//	static char *name[] = {
//	"zero","2","february",
//	"3","4","5","6","7","8","9",
//	"10","11","12"
//	};
//
//	return(n < 1 || n>12) ? name[0] : name[n];
//}
//void  swap(int a, int b) {
//	int temp;  //临时变量
//	temp = a;
//	a = b;
//	b = temp;
//}

//struct point
//{
//	int x;
//	int y;
//
//};
//struct point p =
//{
//	.x = 1,.y = 5
//};
//
//
//struct  a
//{
//	int f;
//	int k;
//};
//struct b
//{
//	struct a f1;
//	
//	struct a k1;
//	
//};
//struct b m =
//{
//	.k1.k = 5,
//    .f1.f = 6
//};

//struct  point
//{
//	int x;
//	int y;
//};
//struct point getstruct(struct point *p)
//{
//	scanf_s("%d", &(*p).x);
//	scanf_s("%d", &(*p).y);
//	return *p;
//};
//struct date
//{
//	int year;
//	int month;
//	int day;
//};
//struct student
//{
//	char name[10];
//	struct date birthday;
//}student1;
//enum
//{
//one = 01,
//two = 02,
//three = 03
//};




main(/*int argc,char *argv[]*/) {
	//文件复制
	/*FILE* fp;
	void filecopy(FILE * ,FILE*);
	if (argc == 1)
		filecopy(stdin, stdout);
	else
		while (--argc > 0)
			if ((fp = fopen_s("",*++argv,"r")) == NULL) {
				printf("cat:%s", *argv);
				return 1;


			}
			else
			{
				filecopy(fp, stdout);
				fclose(fp);
			}
	return 0;*/

	



	/*int flags;
	flags |= two | three;
	flags &= two | three;
	if ((flags & (two | three)) == 0) {
		printf("%d", 1);
	}
	else
	{
		printf("%d", 0);
	}*/
	

	//color


	//enum color 
 //   {
	//	red = 1, green, blue 
	//}favorite_color;

	///*enum  color favorite_color;*/

	///* ask user to choose color */
	//printf("请输入你喜欢的颜色: (1. red, 2. green, 3. blue): ");
	//scanf_s("%d", &favorite_color);

	///* 输出结果 */
	//switch (favorite_color)
	//{
	//case red:
	//	printf("你喜欢的颜色是红色");
	//	break;
	//case green:
	//	printf("你喜欢的颜色是绿色");
	//	break;
	//case blue:
	//	printf("你喜欢的颜色是蓝色");
	//	break;
	//default:
	//	printf("你没有选择你喜欢的颜色");
	//}

	//return 0;







	/*struct student student1 =
	{
		"hahaha",
		1999,10,20
	};
	struct  student student2;
	student2 = student1;
	printf("%s%d%d%d", student2.name,student2.birthday.year, student1.birthday.month, student1.birthday.day);*/



	/*typedef union point
	{
		char *x;
		int y;
	}def;*/
	/*def p;
	p.y = 1;

	printf("%d\n", p.y);
	printf("%\n", &p.x);
	printf("%p\n", &p.y);*/

	/*if(utype == INT)
		printf("%d\n",utype.y)*/




	/*struct point p;
	struct point m = getstruct(&p);
	printf("%d", m.x);*/




	/*printf("%d+%d", m.f1, m.k1.k);*/
	





	/*int i;
	for (i = 1; i < argc; i++)
		printf("%s%s", argv[i], (i < argc - 1) ? "1": "2");
	printf("\n");
	return 0;*/

	/*printf("%s", month_name(1));*/
	/*printf("%d", day_of(2014, 1, 1));
	printf("%d",month_day(2017, 200));*/
	/*strlen("123456");

	char str[50];s
	int len;
	strcpy(str, "123456789");
	len = strlen(str);
	printf("%s,%d", str, len);*/

	/*int arr[] = { 99,78,89,90,78 };
	int len = sizeof(arr) / sizeof(int);
	int i,*p=arr;
	p = arr[0];*/
	/*for (i = 0; i < len; i++) {
		printf("%d,", *(p + i));
	}*/
	/*printf("%d",p);*/
		/*char a = 1, b = 2, c = 3;
		int *p = &c;
		int i;
		for (i = 0; i < 8; i++) {
			printf("%d,", *(p + i));
		}
		return 0;*/
		//int a = 100;
		//char str[20] = "cdwadbawj";
		//printf("%#x\n%#x", &a, str);

		/*int a = 15;
		int *p =&a;
		printf("%d%d", a, *p);*/

		//int a = 15, b = 99, c = 222;
		//int* p = &a;  //定义指针变量
		//*p = b;  //通过指针变量修改内存上的数据
		//c = *p;  //通过指针变量获取内存上的数据
		//printf("%d, %d, %d, %d\n", a, b, c, *p);



	/*int arr[] = { 99, 15, 100, 888, 252 };
	int i, * p = arr, len = sizeof(arr) / sizeof(int);
	for (i = 0; i < len; i++) {
		printf("%d  ", *p++);
	}
	printf("\n");
	return 0;*/
	

		
}


void filecopy(FILE* ifp, FILE* ofp) {

	int c;
	while ((c = getc(ifp)) != EOF)
		putc(c, ofp);
};