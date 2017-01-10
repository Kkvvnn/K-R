/* atof: преобразует строку s в double */

#include <ctype.h>
#include <math.h>

double atof(char s[])
{
    double val, power;
    int i, sign;
    int exp_sign;
    int val_exponent = 0;

    for (i = 0; isspace(s[i]); ++i);    /* пропуск левых символов-разделителей */ 

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-')
        ++i;

    /* целая часть */
    for (val = 0.0; isdigit(s[i]); ++i)
        val = 10.0 * val + (s[i] - '0');

    /* дробная часть */
    if (s[i] == '.')
        ++i;

    for (power = 1.0; isdigit(s[i]); ++i)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val /= power;

    /* экспотенциальная часть */
    if (s[i] == 'e' || s[i] == 'E')
    {
        exp_sign = (s[++i] == '-') ? -1 : 1;

        if (s[i] == '-' || s[i] == '+')
            ++i;

        for (val_exponent = 0; isdigit(s[i]); ++i)
            val_exponent = 10 * val_exponent + (s[i] - '0');

        val_exponent *= exp_sign;
    }

    return sign * val * pow(10, val_exponent);
}
