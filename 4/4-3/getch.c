#include <stdio.h>

#define BUFSIZE 100

char buf[BUFSIZE];    /* буфер для ungetch */
int bufp = 0;         /* след. свободная позиция в буфере */

/* getch: взять (возможно возвращенный) символ */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* ungetch: вернуть символ на ввод */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("слишком много символов\n");
    else
        buf[bufp++] = c;
}
