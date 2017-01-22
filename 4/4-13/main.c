/*      Упражнение 4.13. 
 *  Напишите рекурсивную версию функции reverse(s), 
 *  переставляющую элементы строки в ту же строку в обратном порядке. */

#include <stdio.h>

extern void reverse_recursive(char s[]);

int main(void)
{
    char line[] = "123";

    printf("%s\n", line);
    reverse_recursive(line);
    printf("%s\n", line);

    return 0;
}
