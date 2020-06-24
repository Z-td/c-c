#include <stdio.h>

int stringdex(char s[], char t[])
{
    int i, j, k, m;
    m = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0' && i > m)
            m = i;
    }
    if (m > 0)
        return m;
    else
        return -1;
}

int main()
{
    char s[] = "abcdefghijklmnopqrstuvwxyz1234abcdefghijkl";
    char t[] = "efgh";
    printf("%d\n", stringdex(s, t));
}
