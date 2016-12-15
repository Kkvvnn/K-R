/*      Упражнение 2.3.                                                        *
 *  Напишите функцию htoi(s), которая преобразует последовательность           *
 *  шестнадцатеричных цифр, начинающихся с 0x или 0X, в соответствующее целое. *
 *  Шестнадцатеричными цифрами являются символы 0..9, a..f, A..F.              */

#include <stdio.h>
#include <string.h>     /* for strlen() */
#include <ctype.h>      /* for isdigit(), tolower() */
#include <math.h>       /* for pow() */

#define MAXLINE 100     /* максимальный размер строки */

int htoi(char s_0X[]);
int get_line(char line[], int limit);

int main(void)
{
    char line[MAXLINE];    /* текущая введенная строка*/
    int len;               /* длина текущей строки */

    printf("Введите шестнадцатеричное число, начинающееся на 0x или 0X\n");
    
    while ((len = get_line(line, MAXLINE)) > 0)
    {
        if (line[strlen(line) - 1] == '\n')    /* если строка заканчивается на символ новой строки '\n', удаляем его */
            line[strlen(line) - 1] = '\0';
        
        if (htoi(line) != -1)                  /* если шестнадцатеричное число введено в нужном формате */
            printf("Шестнадцатеричное число %s в десятичном представлении равно %d\n", line, htoi(line));
    }

    return 0;
}

/* переводит шестнадцатеричное число, записанное в виде строки s, в соответствующее целое */
int htoi(char s[])
{
    int i = 0;
    int j = 0;
    int n = 0;
    
    if (s[i] == '0' && tolower(s[i + 1]) == 'x')
    {
        for (i = strlen(s) - 1; tolower(s[i]) != 'x'; --i, ++j)
            if (isdigit(s[i]))
                n = n + (s[i] - '0') * pow(16, j);
            else 
                if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f')
                    n = n + (tolower(s[i]) - 'a' + 10) * pow(16, j);
                else
                {
                    printf("неверный формат шестнадцатеричного числа: присутствуют символы отличные от a..f, A..F, 0..9\n");
                    return -1;
                }
    }
    else
    {
        printf("неверный формат шестнадцатеричного числа: отсутствует префикс 0X либо 0x\n");
        return -1;
    }

    return n;
}

/* считывает строку в s, возвращает её длину */
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
