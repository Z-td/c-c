#include <stdio.h>
#include <stdarg.h>

#define FMTLEN  88 

void minscanf(char* fmt, ...);


int main(void)
{
    int         i;
    unsigned    u;
    char        ch;
    char        ach[10];
    float       f;

    minscanf("%d %u %c %s %f", &i, &u, &ch, ach, &f);
    printf("%d %u %c %s %f\n", i, u, ch, ach, f);

    return 0;
}


void minscanf(char* fmt, ...)
{
    va_list     ap;
    char* pfmt;
    int         i;
    char        cntfmt[FMTLEN];
    int* ival;
    unsigned* uval;
    char* c, * sval;
    float* fval;
    
    va_start(ap, fmt);
    for (pfmt = fmt; *pfmt; ++pfmt) {
        i = 0;
        if (*pfmt != '%') {
            cntfmt[i++] = *pfmt;
            continue;
        }

        cntfmt[i++] = '%';

        while (*(pfmt + 1) && !isalpha(*(pfmt + 1)))
            cntfmt[i++] = *++pfmt;
        cntfmt[i++] = *(pfmt + 1);
        cntfmt[i] = '\0';

        switch (*++pfmt) {
        case 'd':
        case 'i':
            ival = va_arg(ap, int*);
            scanf_s(cntfmt, ival);
            break;
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            uval = va_arg(ap, unsigned*);
            scanf_s(cntfmt, uval);
            break;
        case 'c':
            c = va_arg(ap, char*);
            scanf_s(cntfmt, c);
            break;
        case 'f':
        case 'e':
        case 'E':
        case 'g':
        case 'G':
            fval = va_arg(ap, float*);
            scanf_s(cntfmt, fval);
            break;
        case 's':
            sval = va_arg(ap, char*);
            scanf_s(cntfmt, sval);
            break;
        default:
            scanf_s(cntfmt);
            break;
        }
    }
    va_end(ap);
}
