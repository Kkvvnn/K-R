#include <stdio.h>

#define MAXLINE 100

extern void itob(int n, char s[], int b);

int main(void)
{
    int pattern = 1443;
    int base = 16;
    char line_number[MAXLINE];

    itob(pattern, line_number, base);
    printf("Число %d в системе счисления по основанию %d равно: %s\n", pattern, base, line_number);

    return 0;
}
