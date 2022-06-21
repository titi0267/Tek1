/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday03-timothe.coniel
** File description:
** my_print_comb
*/
#include <unistd.h>

int display(int x)
{
    char letter1;
    char letter2;

    letter1 = (x / 10) + 48;
    letter2 = (x % 10) + 48;
    my_putchar(letter1);
    my_putchar(letter2);

    return (0);
}

int my_print_comb2(void){
    int a = 0;
    int b = 1;

    while (a < 99) {
        b = a + 1;
        while (b < 100) {
        display(a);
        my_putchar(' ');
        display(b);
        if (a != 98 || b != 99) {
            my_putchar(',');
            my_putchar(' ');
        }
        b = b + 1;
    }
    a = a + 1;
    }
}