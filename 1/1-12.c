/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.12
 *  Напишите программу для вывода входного потока по одному слову в строке.
 */

#include <stdio.h>

int main(void)
{
    int c;
    int pred;                       /* предыдущий введенный символ */
    
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')              /* табуляцию считаем пробелом */
            c = ' ';
        
        if (c != ' ')
            putchar(c);
        else
            if (pred != ' ')
                putchar('\n');
        pred = c;
    }
    
    return 0;
}
