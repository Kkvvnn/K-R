/*
 *      Упражнение 1.12
 *  Напишите программу для вывода входного потока по одному слову в строке.
 *
 *	Vladimir Kashin
 *	<vova6281527@gmail.com>
 *	26-JAN-2017
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
