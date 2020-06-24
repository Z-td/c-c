#include<stdio.h>
lower( c);
 int main()
 {
	 int c;
	 while ((c=getchar())!=EOF)
	 {
		 putchar(lower(c));
	 }
	
 }

 lower( c) {
	 return ((c >= 'A' && c <= 'Z') ? c + 'a'-'A' : c);
	
}

