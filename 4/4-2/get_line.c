/* get_line: считывает строку в s, возвращает её длину */

#include <stdio.h>

int get_line(char s[], int lim)
{
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    
    if (c == '\n')
        s[i++] = c;
    
    s[i] = '\0';

    return i;
}
