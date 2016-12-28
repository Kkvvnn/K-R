/* itoa: преобразование целого n в строку s */

extern void reverse(char s[]);

void itoa(int n, char s[], int width)
{
    int i = 0;
    int sign = n;

    if (sign < 0)      /* если n отрицательное...     */
        n = -n;        /* ...делаем его положительным */
    
    do
    {
        s[i++] = n % 10 + '0';
    }
    while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    while (i < width)
        s[i++] = ' ';

    s[i] = '\0';

    reverse(s);
}
