/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.10.
 *  Напишите программу, копирующую вводимые символы в выходной поток
 *  с заменой символа табуляции на \t, символа забоя на \b и каждой
 *  наклонной черты на \\. Это сделает видимыми все символы табуляции и забоя.
 */

#include <stdio.h>

int main(void)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else
            putchar(c);
    }

    return 0;
}
