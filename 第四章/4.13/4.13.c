#include <stdio.h>
static int sp1;
static int sp2;
void reverse(char *s);
void main() {
    char s[100];
    scanf_s("%s", s, 100);
    reverse(s);
    s[sp2] = '\0';
    printf("%s", s);
}

void reverse(char *s) {
    char c = '\0';
    if (s[sp1] != '\0') {
        c = s[sp1++];
            reverse(s);
    }
    if (sp2 < sp1 && c != '\0')
        s[sp2++] = c;

}