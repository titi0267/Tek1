/*
** EPITECH PROJECT, 2020
** rush-1-4.c by Audric MOINE & Elliot WALDVOGEL
** File description:
** rush-1-4
*/

void check_special_errors4(int nb_x, int nb_y)
{
    char str[] = "Invalid size";

    if (nb_x == 1 && nb_y == 1)
        my_putchar('B');
    else
        for (int i = 0; str[i] != '\0'; i++)
            my_putchar(str[i]);
}

void check_error4(int nb_x, int nb_y)
{
    if ((nb_x == 1 && nb_x <= 2147483647) && 
    (nb_y > 1 && nb_y <= 2147483647)) {
        for (int i = 0; i < nb_y; i++) {
            for (int j = 0; j < nb_x; j++) {
                my_putchar('B');
                my_putchar('\n');
            }
        }
    }
    else if ((nb_x > 1 && nb_x <= 2147483647) && 
    (nb_y == 1 && nb_y <= 2147483647)) {
        for (int i = 0; i < nb_x; i++)
            my_putchar('B');
    }
    else
        check_special_errors4(nb_x, nb_y);
}

int last_line4(int nb_x)
{
    my_putchar('A');
    for (int i = 0; i < (nb_x - 2); i++)
        my_putchar('B');
    my_putchar('C');
    return (0);
}

int middle_lines4(int nb_x, int nb_y)
{
    for (int i = 1; i < (nb_y - 1); i++) {
        my_putchar('\n');
        my_putchar('B');
        for (int j = 0; j < (nb_x - 2); j++) {
            my_putchar(' ');
        }
        my_putchar('B');
    }
    my_putchar('\n');
    last_line4(nb_x);
    return (0);
}

int rush(int nb_x, int nb_y)
{
    if ((nb_x > 1 && nb_y > 1) && (nb_x <= 2147483647 && nb_y <= 2147483647)) {
        my_putchar('A');
        for (int i = 0; i < (nb_x -2); i++)
            my_putchar('B');
        my_putchar('C');
        middle_lines4(nb_x, nb_y);
        return (0);
    }
    else
        check_error4(nb_x, nb_y);
}