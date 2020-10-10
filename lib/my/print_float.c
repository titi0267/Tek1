/*
** EPITECH PROJECT, 2020
** print_float
** File description:
** print_float
*/

int print_float(float a)
{
    int b = (int)a;
    float c = a - b;
    c *= 100;
    int d = c;
    my_put_nbr(b);
    my_putchar('.');
    my_put_nbr(d);
    return (0);
}