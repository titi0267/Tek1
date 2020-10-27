#include "include/my_structs.h"
#include "include/my.h"
#include "include/operations.h"
#include "include/police.h"
#include <stdlib.h>

void *print_iadd(number_t *num)
{
    if (num->sign == -1 && (my_strcmp(num->numb, "0") != 0))
        my_putstr("-");
    my_putstr(num->numb);
    my_putchar('\n');
}

number_t *infin_add(char *n1, char *n2)
{
    number_t *num1 = malloc(sizeof(number_t));
    number_t *num2 = malloc(sizeof(number_t));
    number_t *result = malloc(sizeof(number_t));
    char *t1 = my_strdup(n1);
    char *t2 = my_strdup(n2);
    
    result=adapt_numbers(&t1,&t2,num1,num2);
    print_iadd(result);
    return (result);
}
int main(int argc, char **argv)
{
    infin_add(argv[1],argv[2]);
}
