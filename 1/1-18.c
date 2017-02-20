/*
 *      Упражнение 1.18.
 *  Напишите программу, которая будет в каждой вводимой строке заменять
 *  стоящие подрят символы пробелов и табуляций на один пробел и удалять пустые строки.
 *
 *	Vladimir Kashin
 *	<kkvvnn89@gmail.com>
 *	26-JAN-2017
 */

#include <stdio.h>

#define MAXLINE 1000        /* максимальная длина строки */

int getline_my(char s[], int limit);
void del_space(char to[], char from[]);

int main(void)
{
    char line[MAXLINE];
    int len;                /* длина текущей строки */
    char line_one_space[MAXLINE];

    while ((len = getline_my(line, MAXLINE)) > 0)
    {
        if (len > 1)
        {
            del_space(line_one_space, line);
            printf("%s", line_one_space);
        }
    }

    return 0;
}

/* Читает строку в s, возвращает её длину */
int getline_my(char s[], int limit)
{
    int i, c;

    for (i =0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}

/* Копирует строку from в строку to, 
    заменяя подрят стоящие пробелы и символы табуляции на один пробел*/
void del_space(char to[], char from[])
{
    int i, j, k;
    char pred;

    for (j = 0; from[j] != '\0'; ++j);      /* Определяем длину строки */

    for (i = 0, k =0; i <= j; ++i)
    {
        if (from[i] == '\t')                /* Табуляцию считаем пробелом */
            from[i] = ' ';
        
        if (from[i] != ' ')
        {
            to[k] = from[i];
            ++k;
        }
        else if (pred != ' ')
        {
            to[k] = from[i];
            ++k;
        }
        pred = from[i];
    }
    to[++i] = '\0';
}
