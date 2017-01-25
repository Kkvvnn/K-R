/*  Written by Vladimir Kashin <kkvvnnrussia@gmail.com>
 *
 *      Упражнение 1.15.
 *  Перепишите программу преобразования температур,
 *  выделив само преобразование в отдельную функцию.
 */

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int fahr_to_celsius(int fahr);

int main(void)
{
    int fahr;
    
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%3d%6d\n", fahr, fahr_to_celsius(fahr));

    return 0;
}

/* fahr_to_celsius: переводит температуру 
 * из шкалы по Фаренгейту в шкалу по Цельсию */
int fahr_to_celsius(int fahr)
{
    return 5 * (fahr - 32) / 9;
}
