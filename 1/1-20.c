/*
 *      Упражнение 1.20.
 *  Напишите программу detab, заменяющую символы табуляции во вводимом
 *  тексте нужным числом пробелов (до следующего "стопа" табуляции).
 *  Предполагается, что "стопы" табуляции расставлены на фиксированном
 *  расстоянии друг от друга, скажем, через n позиций. Как лучше
 *  задавать n - в виде значения переменной или в виде именованной константы?
 *
 *	Vladimir Kashin
 *	<vova6281527@gmail.com>
 *	26-JAN-2017
 */

#include <stdio.h>

#define MAXLINE     1000    /* Максимальная длина строки */
#define N           8       /* ширина "стопа" табуляции */

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


/*  Печатает строку s с заменой табуляции нужным числом     *
 *   пробелов до следующего "стопа" табуляции.              *
 *   stop_tab - расстояние между "стопами" табуляций        */
void detab(char s[], int stop_tab)
{
    int i, j;
    int t = 0;
    int n = 1;
    
    for (i = 0; s[i] != '\0'; ++i)
    {
        j = i + t - n;
        if (s[i] == '\t')
        {
            ++n;
            while ((stop_tab - j % stop_tab) != 1)
            {
                putchar('#');
                ++t;
                ++j;
            }
        }
        else
            putchar(s[i]);
    }
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

