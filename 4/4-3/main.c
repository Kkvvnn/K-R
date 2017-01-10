/* калькулятор с обратной польской записью */

#include <stdio.h>
#include <stdlib.h>    /* для atof() */

#define MAXOP 100      /* макс. размер операнда или оператора */
#define NUMBER '0'     /* признак числа */

extern int getop(char []);
extern void push(double);
extern double pop(void);

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop (s)) != EOF)
    {
        switch (type)
        {
            case NUMBER: push (atof(s)); break;
            
            case '+'   : push (pop() + pop()); break;
            
            case '*'   : push (pop() * pop()); break;
            
            case '-'   : op2 = pop();
                         push (pop() - op2); break;
            
            case '/'   : op2 = pop();
                         (op2 != 0.0) ? push(pop() / op2) : printf("ошибка: деление на нуль\n"); break;
            
            case '%'   : op2 = pop();
                         if (op2 != 0)
                             push ((int)pop() % (int)op2);
                         else
                             printf("ошибка: невозможно вычислить остаток от деления на нуль\n"); break;
            
            case '\n'  : printf("\t%.8g\n", pop()); break;
            
            default    : printf("ошибка: неизвестная операция %s\n", s); break;
        }
    }
    return 0;
}
