/*      Упражнение 4.12.
 *  Напишите рекурсивную версию функции itoa - преобразование целого числа в строку путём рекурсивного вызова. */

#include <stdio.h>

#define MAXLINE 100

extern void itoa_recursive(int n, char s[]);

int main(void)
{
    int pattern = 2017, pattern2 = -557;
    char line[MAXLINE];

    itoa_recursive(pattern, line);
    printf("%s\n", line);

    itoa_recursive(pattern2, line);
    printf("%s\n", line);

    return 0;
}
