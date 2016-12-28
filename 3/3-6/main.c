/*		Упражнение 3.6                                                                           *
*	Напишите версию itoa с дополнительным третьим аргументом, задающим минимальную ширину поля.  *
*	При необходимости преобразованное число должно слева дополняться пробелами.                  */

#include <stdio.h>

#define MAXLINE 100

extern void itoa(int n, char s[], int width);

int main(void)
{
    int pattern = -1234567;
	int width = 15;
    char line_number[MAXLINE];

    itoa(pattern, line_number, width);
    printf("%s\n", line_number);

    return 0;
}
