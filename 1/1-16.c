/*      Упражнение 1.16.
 *  Перепишите main предыдущей программы так, чтобы она могла 
 *  печатать самую длинную строку без каких-либо ограничений на ее размер. */

#include <stdio.h>

#define MAXLINE 5    /* максимальный размер вводимой строки */

int get_line(char line[], int limit_lin_line);
void copy(char to[], char from[]);

int main(void)
{
    int len, len2 = 0;                  /* длина текущей строки */
    int max = 0;              /* длина максимальной из просмотренных строк */
    char line[MAXLINE];       /* текущая строка */
    char longest[MAXLINE];    /* самая длинная строка */
    char bufer[MAXLINE];      /* для запоминания части строки, превышающей максимальный размер */
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n')
            len2 += len;
        else
        {
            len2 += --len;
            
            if (len2 > max)
            {
                max = len2;
                len2 = 0;
                copy(longest, line);
            }
        }
    }

    if (max > 0)
        printf("\n%s%d\n", longest, max);

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
