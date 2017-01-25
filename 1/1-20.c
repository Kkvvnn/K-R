/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.20.
 *  Напишите программу detab, заменяющую символы табуляции во вводимом
 *  тексте нужным числом пробелов (до следующего "стопа" табуляции).
 *  Предполагается, что "стопы" табуляции расставлены на фиксированном
 *  расстоянии друг от друга, скажем, через n позиций. Как лучше
 *  задавать n - в виде значения переменной или в виде именованной константы?
 */

#include <stdio.h>

#define MAXLINE     1000    /* Максимальная длина строки */
#define N           5       /* ширина "стопа" табуляции */

int get_line(char line[], int limit);
void detab(char line[], int stop_tab);

int main(void)
{
    char line[MAXLINE];     /* Текущая строка */
    int len;                /* Длина текущей строки */

    while ((len = get_line(line, MAXLINE)) > 0)
        detab(line, N);

    return 0;
}


/* Читает вводимую строку в s, возвращает её длину  */
int get_line(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

/*  Печатает строку s с заменой табуляции нужным числом     *
 *   пробелов до следующего "стопа" табуляции.              *
 *   stop_tab - расстояние между "стопами" табуляций        */
void detab(char s[], int stop_tab)
{
    int i, j;
    
    for (i = 0, j = 0; s[i] != '\0'; ++i, ++j)
    {
        if (s[i] == '\t')
            while ((stop_tab - j % stop_tab) != 1)
            {
                putchar('#');
                ++j;
            }
        else
            putchar(s[i]);
    }
}
