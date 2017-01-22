/*      Упражнение 1.16.
 *  Перепишите main предыдущей программы так, чтобы она могла 
 *  печатать самую длинную строку без каких-либо ограничений на ее размер. */

#include <stdio.h>

#define MAXLINE 20    /* максимальный размер вводимой строки */

int get_line(char line[], int limit_lin_line);
void copy(char to[], char from[]);

int main(void)
{
    int len;                  /* длина текущей строки */
    int max = 0;              /* длина максимальной из просмотренных строк */
    char line[MAXLINE];       /* текущая строка */
    char longest[MAXLINE];    /* самая длинная строка */
    char bufer[MAXLINE];      /* для запоминания части строки, превышающей максимальный размер */
    
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    
    if (max > 0)              /* была ли введена хоть одна строка? */
        printf("%s %d\n", longest, max);

    return 0;
}

/* get_line: читает строку в s, возвращает её длину. lim - максимальная длина вводимой строки */
int get_line(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;

    s[i] = '\0';

    return i;
}

/* copy: копирует строку from в строку to; to достаточно большой */
void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}
