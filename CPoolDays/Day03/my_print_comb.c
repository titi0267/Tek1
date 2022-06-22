/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday03-timothe.coniel
** File description:
** my_print_comb
*/
#include <unistd.h>

int print_comb(char a, char b, char c) {
    while (c <= '9') {
            my_putchar(a);
            my_putchar(b);
            my_putchar(c);
            if (a < '7') {
            my_putchar(',');
            my_putchar(' ');
            }
            c++;
            }
}

int my_print_comb(void) {
    char a = '0';
    char b = '1';
    char c = '2';

    while (a <= '7') {
        while (b <= '8') {
            print_comb(a, b, c);
            b++;
            c = b + 1;
        }
        a++;
        b = a + 1;
        c = b + 1;
    }

    return(0);
}