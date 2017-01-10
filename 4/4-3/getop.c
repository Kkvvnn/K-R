/* getop: получает следущий оператор или операнд */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

extern int getch(void);
extern void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;                /* не число */
    
    i = 0;
    
    if (isdigit (c))             /* накапливаем целую цасть */
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')                /* накапливаем дробную часть */
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}
