/*
 *      Упражнение 1.8.
 *  Напишите программу для подсчета пробелов, табуляций и новых строк.
 *
 *	Vladimir Kashin
 *	<vova6281527@gmail.com>
 *	26-JAN-2017
 */

#include <stdio.h>

int main(void)
{
    int c;
    int space = 0;    /* количество пробелов */
    int tab = 0;      /* количество табуляций */
    int nl = 0;       /* количество строк */

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++space;

        if (c == '\t')
            ++tab;

        if (c == '\n')
            ++nl;
    }

    printf("\nпробелов:  %5d\nтабуляций: %5d\nстрок:     %5d\n", space, tab, nl);

    return 0;
}
