/*		Упражнение 4.2 
 *	Дополните функцию atof таким образом, чтобы она справлялась с числами вида 123.45e-6, 
 *	в которых после мантиссы может стоять e (или E) с последующим порядком (быть может, со знаком)
 */

#include <stdio.h>

#define MAXLINE 100

extern int get_line(char line[], int limit);
extern double atof(char line[]);

int main(void)
{
    double sum = 0;
    char line[MAXLINE];

    while (get_line(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}
