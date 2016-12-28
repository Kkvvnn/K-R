extern void reverse(char s[]);

void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;

    if (sign < 0)       /* если n отрицательное...     */
        n = -n;         /* ...делаем его положительным */
    
    do
    {
        if ((n % b) < 10 )
            s[i++] = n % b + '0';
        else
            s[i++] = n % b - 10 + 'A'; 
    }
    while (n = n / b);  /* с каждым шагом "отбрасываем" старший разряд, пока не получим ноль */
    
    if (b == 8)
        s[i++] = '0';

    if (b == 16)
    {
        s[i++] = 'x';
        s[i++] = '0';
    }
    
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}
