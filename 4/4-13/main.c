/*      Упражнение 4.13. 
 *  Напишите рекурсивную версию функции reverse(s), 
 *  переставляющую элементы строки в ту же строку в обратном порядке. */

#include <stdio.h>

extern void reverse_recursive(char s[]);

int main(void)
{
    char line[] = "1234567890";
    char line2[] = "Hello World!";

    printf("%s\n", line);
    reverse_recursive(line);
    printf("%s\n\n", line);

    printf("%s\n", line2);
    reverse_recursive(line2);
    printf("%s\n", line2);

    return 0;
}
