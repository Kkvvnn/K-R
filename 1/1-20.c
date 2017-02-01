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
 *	31-JAN-2017
 */

#include <stdio.h>

#define MAXLINE     1000    /* Максимальная длина строки */
#define N           4       /* ширина табуляции */

int get_line(char line[], int limit);
void detab(char line[], int stop_tab);

int main(void)
{
    char line[MAXLINE];     /* Текущая строка */

    while (get_line(line, MAXLINE) > 0)
        detab(line, N);

    return 0;
}


/* detab: печатает строку s с заменой табуляции нужным числом пробелов 
   до следующего "стопа" табуляции. tab_width - ширина табуляции */
void detab(char s[], int tab_width)
{
    int i;
    int space = 0;    /* количество пробелов необходимых до следующего "стопа" табуляции */
    int c = 0;        /* количество символов, введенных перед следующим символом табуляции */
    
    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] != '\t')
        {
            putchar(s[i]);
            ++c;
        }
        else
        {
            space = tab_width - c % tab_width;
            c = 0;

            while (space--)
                putchar(' ');
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

