/* getop: получает следущий оператор или операнд */

#include <stdio.h>
#include <ctype.h>

#define NUMBER '0'

extern int getch(void);
extern void ungetch(int);

int getop(char s[])
{
    int i, c;
    int c_next;

    /* пропускаем табуляцию и пробелы */
    while ((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c;                               /* не число и не знак минус '-' */

    if (c == '-')                               /* если после минуса... */
        if (isspace(c_next = getch()))          /* ...следующий символ - символ пустого пространства */
        {
            ungetch(c_next);                    /* возвращаем его на ввод */
            return c;                           /* оператор '-' возвращаем в main() */
        }
        else 
            ungetch(c_next);                   

    i = 0;
    
    if (isdigit (c) || c == '-')                /* накапливаем целую цасть */
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')                               /* накапливаем дробную часть */
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';

    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}
