/*
 *      Упражнение 1.17.
 *  Напишите программу печати всех вводимых строк, содержащих более 80 символов.
 *
 *	Vladimir Kashin
 *	<kkvvnn89@gmail.com>
 *	26-JAN-2017
 */

#include <stdio.h>

#define MAXLINE 1000        /* Максимальный размер строки */

int getline_my(char s[], int limit);

int main(void)
{
    int i;
    char line[MAXLINE];
    int len = 0;            /* Длина текущейстроки */

    while ((len = getline_my(line, MAXLINE)) > 0)
    {
        if (len > 80)
            printf("%s", line);
    }

    return 0;
}

int getline_my(char s[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}
