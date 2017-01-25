/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.19.
 *  Напишите функцию reverse(s), которая переписывает свой строковый 
 *  аргумент s в обратном порядке. 
 *      Воспользуйтесь ею для написания программы, которая бы 
 *  выполняла такое обращение над каждой строкой входного потока по очереди.
 */

#include <stdio.h>

#define MAXLINE 1000        /* Максимальный размер строки */

void reverse(char line[]);
int get_line(char line[], int limit);

int main(void)
{
    char line[MAXLINE];     /* Текущая строка */
    int len;                /* Длина текущей строки */

    while ((len = get_line(line, MAXLINE)) > 0)
    {
        reverse(line);
        printf("%s\n", line);
    }
    
    return 0;
}

/* Переписывает строку s в обратном порядке */
void reverse(char s[])
{
    int i, j;
    int temp;

    for (i = 0; s[i] != '\0' && s[i] != '\n'; ++i);     /* Определяем длину строки, без заверщающих '\n' и '\0' */

    for (j = 0; j < i; ++j, --i)
    {
        temp = s[j];
        s[j] = s[i - 1];
        s[i - 1] = temp;
    }
}

/* Читает строку в s, возвращает её длину */
int get_line(char s[], int limit)
{
    int i, c;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';

    return i;
}
