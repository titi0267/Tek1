/*
** EPITECH PROJECT, 2020
** task04
** File description:
** isneg
*/

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    my_putchar('\n');
}