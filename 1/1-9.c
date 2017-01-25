/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.9
 *  Напишите программу, копирующую символы ввода в выходной
 *  поток и заменяющую стоящие подряд пробелы на один пробел.
 */

#include <stdio.h>

int main(void)
{
    int c;
    int pred;   /* предыдущий введенный символ */

    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
            putchar(c);
        else
            if (pred != ' ')
                putchar(c);
        pred = c;
    }
    
    return 0;
}
