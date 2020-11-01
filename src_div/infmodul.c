#include "../include/my_structs.h"
#include "../include/infdiv.h"
#include "../include/infsubst.h"
#include "../include/my.h"
#include <stdlib.h>


void print_numbert(number_t *toprint){
    if(toprint->sign == -1)
        my_putchar('-');
    my_putstr(toprint->numb);
    my_putstr("\n");
}
number_t *inf_modul(char *left, char *right)
{
    char *remain;
    number_t *result = inf_div(left, right, &remain);
    free(result->numb);
    result->numb = remain;
    return (result);
}

int main(int ac, char **av) 
{
    print_numbert(inf_modul(av[1],av[2]));

}