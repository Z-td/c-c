#include<stdio.h>
#include<string.h>

main() {
    int s =any("1245", "1");
    printf("%d", s);
}
 any(char s1[], char s2[]) {
     int i, j, k;

    for (i = 0; s1[i] != '\0'; i++) {
        for ( j = 0; s2[j] !='\0'; j++)
        {
            if (s1[i]==s2[j]) 
            {
               return i+1;
            }
            
               
        }
        
    }
    return -1;
    
}
