/*      Упражнение 3.2.                                                                      *
 *  Напишите функцию escape(s, t), которая при копировании текста из t в s                   *
 *  преобразует такие символы, как новая строка и табуляция в "видимые последовательности    *
 *  символов" (вроде \n и \t). Используйте инструкцию switch. Напишите функцию, выполняющую  *
 *  обратное преобразование эскейп-последовательностей в настоящие символы                   */

#include <stdio.h>

#define MAXLINE 1000        /* максимальный размер строки */

extern int get_line(char s[], int lim);
extern void escape(char s[], char t[]);
extern void escape_inverse(char s[], char t[]);

int main(void)
{
    char line[MAXLINE];     /* вводимая строка */
    char sline[MAXLINE];    /* строка с преобразованными эскейп-последовательностями */

    while (get_line(line, MAXLINE) != 0)
    {
        escape(sline, line);
        printf("%s\n", sline);

        escape_inverse(sline, line);
        printf("%s\n", sline);
    }

    return 0;
}
