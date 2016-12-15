/*  Упражнение 1.13.                                                                *
 *      Напишите программу для вывода гистограммы длин слов во входном потоке.      *
 *      Построить гистограмму с горизонтальными рядами довольно легко,              *
 *      а вот с вертикальными столбцами труднее.                                    */

#include <stdio.h>

#define IN_WORD     1
#define OUT_WORD    0

#define MAX_WORD    15      /* максимальная длина слова */

int main(void)
{
    int i, c;
    int j = 0;
    int state = OUT_WORD;
    int word_lenght[MAX_WORD];

    for (i = 0; i < MAX_WORD; ++i)
        word_lenght[i] = 0;

    while ((c = getchar()) != EOF)
    {
        if ((c != ' ') && (c != '\t') && (c != '\n'))
        {
            state = IN_WORD;
            ++j;
        }
        else if (state == IN_WORD)
        {
            if (j <= MAX_WORD)
                ++word_lenght[j];
            j = 0;
        }
    }

    /* Вывод горизонтальной гистограммы */
    for (i = 1; i < MAX_WORD; ++i)
    {
        printf("%2d : ", i);
        for (j = 0; j < word_lenght[i]; ++j)
            putchar('#');
        putchar('\n');
    }

    putchar('\n');

    /* Вывод вертикальной гистограммы */
    for (i = 1; i < MAX_WORD; ++i)
        printf("%3d", i);
    putchar('\n');

    for (j = 1; j < 10; ++j)
    {    
        for (i =1; i < MAX_WORD; ++i)
            if (word_lenght[i] > 0)
            {
                printf("%3c", '#');
                --word_lenght[i];
            }
            else 
                printf("%3c", ' ');
        
            putchar('\n');
    }

    return 0;
}
