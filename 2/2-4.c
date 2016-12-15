/*      Упражнение 2.4.                                         *
 *  Напишите версию функции squeeze(s1, s2), которая удаляет из *
 *  строки s1 все символы, встречающиеся в строке s2.           */

#include <stdio.h>

void squeeze(char s1[], char s2[]);

int main(void)
{
    char s1[] = "123456789";
    char s2[] = "2468";
    
    squeeze(s1, s2);
    printf("%s\n", s1);
    
    return 0;
}

/* Удаляет из строки s все символы, встречающиеся в строке t */
void squeeze(char s[], char t[])
{
    int i, j, k;
    int found;

    for (i = 0, j = 0; s[i] != '\0'; ++i)
    {
        for (k = 0, found = 0; t[k] != '\0'; ++k)
            if (s[i] == t[k])
                found = 1;
        
        if (found == 0)
             s[j++] = s[i];
    }

    s[j] = '\0';
}
