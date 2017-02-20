/*
 *      Упражнение 1.14.
 *  Напишите программу для вывода гистограммы частот,
 *  с которыми встречаются во входном потоке различные символы.
 *
 *	Vladimir Kashin
 *	<kkvvnn89@gmail.com>
 *	26-JAN-2017
 */

#include <stdio.h>

int main(void)
{
    int c;
    int i, j;
    int ascii[127];

    for (i = 0; i < 127; ++i)
        ascii[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if (c < 127)
            ++ascii[c];
    }

    for (i = 32; i < 127; ++i)
    {
        if (ascii[i] > 0)
        {
            printf("\"");
            putchar(i);
            printf("\": ");
        for (j = 1; j <= ascii[i]; ++j)
            putchar('#');
        putchar('\n');
        }
    }
    
    return 0;
}
