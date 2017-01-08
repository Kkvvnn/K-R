/*    Упражнение 4.1                                                                *
 * Напишите функцию strindex(s, t), которая выдаёт позицию самого правого вхождения *
 * строки t в строку s или -1, если вхождения не обнаружено.                        */

#include <stdio.h>

#define MAXLINE 1000

extern int get_line(char line[], int lim);
extern int strindex(char source[], char searchfor[]);

int main(void)
{
    char line[MAXLINE];
    int found = 0;
    int right_index;    /* индекс самого правого вхождения */

    char pattern[] = "abc";

    while (get_line(line, MAXLINE) > 0)
        if ((right_index = strindex(line, pattern)) >= 0)
        {
            printf("%s\t%d\n", line, right_index);
            ++found;
        }

    return found;
}
