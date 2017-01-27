/*
 *      Упражнение 1.16.
 *  Перепишите main предыдущей программы так, чтобы она могла
 *  печатать самую длинную строку без каких-либо ограничений на ее размер.
 *
 *	Vladimir Kashin
 *	<vova6281527@gmail.com>
 *	26-JAN-2017
 */

#include <stdio.h>

#define MAXLINE 10    /* максимальный размер вводимой строки */

int get_line(char line[], int limit_lin_line);
void copy(char to[], char from[]);

int main(void)
{
    int len;                       /* длина текущего фрагмента строки */
    int len_total = 0;             /* общая длина строки */
    int max = 0;                   /* длина максимальной из просмотренных строк */
    
    char line[MAXLINE];            /* текущий фрагмент строки */
    char first[MAXLINE];           /* первый фрагмент текущей строки */
    char penult[MAXLINE];          /* предпоследний фрагмент текущей строки */
    
    char long_first[MAXLINE];      /* первый фрагмент самой длинной строки, превышающей MAXLINE */
    char long_penult[MAXLINE];     /* предпоследний фрагмент самой длинной строки */
    char long_last[MAXLINE];       /* последний фрагмент самой длинной строки*/
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (line[len - 1] != '\n')               /* прочитан фрагмент, за которым строка ещё продолжается */
        {
            if (len_total == 0)                  /* если строка только началась */
                copy(first, line);               /* сохраняем первый фрагмент строки */
            
            len_total += len;                    /* увеличиваем общую длину строки на длину фрагмента */
            copy(penult, line);                  /* сохраняем текущий(предпоследний) фрагмент */
        }
        else                               /* прочитан последний фрагмент строки */
        {
            len_total += --len;            /* увеличиваем общую длину на длину фрагмента без завершающего \n */
            
            if (len_total > max)           /* если строка длиннее предыдущей самой длинной */
            {
                max = len_total;           /* сохраняем её длину */
                copy(long_last, line);     /* сохраняем её последний фрагмент */
                copy(long_first, first);   /* сохраняем её первый фрагмент */
                copy(long_penult, penult); /* сохраняем её предпоследний фрагмент */
            }

            len_total = 0;  /* обнуляем общую длину строки перед переходом к следующей строке */
        }
    }

    if (max > 0)
        printf("\nСамая длинная строка из введенных:\n");
    
    if (max >= 3 * (MAXLINE - 1))
        printf("%s...%s%s", long_first, long_penult, long_last);  /* строка состоит из 4-х и более фрагментов */
    else if (max >= 2 * (MAXLINE - 1))
        printf("%s%s%s", long_first, long_penult, long_last);     /* строка состоит из 3-х фрагментов */
    else if (max >=  (MAXLINE - 1))
        printf("%s%s", long_first, long_last);                    /* строка состоит из 2-х фрагментов */
    else if (max > 0)
        printf("%s", long_last);                                  /* строка состоит только из 1-го фрагмента */

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
