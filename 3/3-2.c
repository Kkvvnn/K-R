/*      Упражнение 3.2.                                                                      *
 *  Напишите функцию escape(s, t), которая при копировании текста из t в s                   *
 *  преобразует такие символы, как новая строка и табуляция в "видимые последовательности    *
 *  символов" (вроде \n и \t). Используйте инструкцию switch. Напишите функцию, выполняющую  *
 *  обратное преобразование эскейп-последовательностей в настоящие символы                   */

#include <stdio.h>

#define MAXLINE 1000        /* максимальный размер строки */

int get_line(char s[], int lim);
void escape(char s[], char t[]);

int main(void)
{
    char line[MAXLINE];     /* вводимая строка */
    char sline[MAXLINE];    /* строка с преобразованными эскейп-последовательностями */

    while (get_line(line, MAXLINE) != 0)
    {
        escape(sline, line);
        printf("%s\n", sline);
    }

    return 0;
}

/* escape: копирует t в s, преобразуя символы новой строки и табуляции в видимые
   последовательности символов(\n и \t)*/
void escape(char s[], char t[])
{
    int i, j;
    
    for (i = 0, j = 0; t[i] != '\0'; ++i, ++j)
        switch (t[i])
        {
            case '\n': s[j++] = '\\';
                       s[j] = 'n';
                       break;
            
            case '\t': s[j++] = '\\';
                       s[j] = 't';
                       break;
            
            default: s[j] = t[i];
                     break;
        }
    s[j] = '\0';
}

/* get_line: считывает строку в s, возвращает её длину */
int get_line(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';

    return i;
}
