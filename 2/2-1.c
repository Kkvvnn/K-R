/*      Упражнение 2.1.                                                                  *
 *  Напишите программу, которая будет выдавать диапазоны значений типов char, short,     *
 *  int и long, описаных как signed и как unsigned, с помощью печати соответствующих     *
 *  значений из стандартных заголовочных файлов и путем прямого вычисления. Определите   *
 *  диапазоны чисел с плавающей точкой различных типов. Вычислить эти диапазоны сложнее. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
    putchar('\n');
    /* signed */
    printf("Char:  %12d %12d\n", CHAR_MIN, CHAR_MAX);
    printf("Short: %12d %12d\n", SHRT_MIN, SHRT_MAX);
    printf("Int:   %12d %12d\n", INT_MIN, INT_MAX);
    printf("Long:  %12ld %12ld\n\n", LONG_MIN, LONG_MAX);

    /* unsigned */
    printf("Unsigned char:  %d %d\n", 0, UCHAR_MAX);
    printf("Unsigned short: %d %d\n", 0, USHRT_MAX);
    printf("Unsigned int:   %d %u\n", 0, UINT_MAX);
    printf("Unsigned long:  %d %lu\n\n", 0, ULONG_MAX);

    /* float */
    printf("Float:       %15e %15e\n", FLT_MIN, FLT_MAX);
    printf("Double:      %15e %15e\n", DBL_MIN, DBL_MAX);
    printf("Long double: %15Le %15Le\n\n", LDBL_MIN, LDBL_MAX);

    return 0;
}



