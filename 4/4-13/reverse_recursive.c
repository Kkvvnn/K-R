/* reverse_recursive: рекурсивно переставляет 
 * элементы строки в ту же строку в обратном порядке */

#include <string.h>

void reverse_recursive(char s[])
{
    static int i;
    int len = strlen(s) - ++i;

    if (len >= 0)
        reverse_recursive(s);

    s[i - 1] = s[len];
}
