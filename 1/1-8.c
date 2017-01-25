/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.8.
 *  Напишите программу для подсчета пробелов, табуляций и новых строк.
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
