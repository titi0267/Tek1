/*
** EPITECH PROJECT, 2020
** rush-1-1.c by Audric MOINE & Elliot WALDVOGEL
** File description:
** rush-1-1
*/

void check_special_errors1(int nb_x, int nb_y)
{
    char str[] = "Invalid size";

    if (nb_x == 1 && nb_y == 1)
        my_putchar('o');
    else
        for (int i = 0; str[i] != '\0'; i++)
            my_putchar(str[i]);
}

void check_error1(int nb_x, int nb_y)
{
    if ((nb_x == 1 && nb_x <= 2147483647) && (nb_y > 1 && nb_y <= 2147483647)) {
        for (int i = 0; i < nb_x; i++) {
            my_putchar('o\n');
            for (int j = 0; j < (nb_y - 2); j++)
                my_putchar('|\n');
            my_putchar('o');
        }
    }
    else if ((nb_x > 1 && nb_x <= 2147483647) && 
    (nb_y == 1 && nb_y <= 2147483647)) {
        my_putchar('o');
        for (int i = 0; i < (nb_x - 2); i++)
            my_putchar('-');
        my_putchar('o');
    }
    else
        check_special_errors1(nb_x, nb_y);
}

int last_line1(int nb_x)
{
    my_putchar('o');
    for (int i = 0; i < (nb_x - 2); i++)
        my_putchar('-');
    my_putchar('o');
    return (0);
}

int middle_lines1(int nb_x, int nb_y)
{
    for (int i = 1; i < (nb_y - 1); i++) {
        my_putchar('\n');
        my_putchar('|');
        for (int j = 0; j < (nb_x - 2); j++)
            my_putchar(' ');
        my_putchar('|');
    }
    my_putchar('\n');
    last_line1(nb_x);
    return (0);
}

int rush(int nb_x, int nb_y)
{
    if ((nb_x > 1 && nb_y > 1) && (nb_x <= 2147483647 && nb_y <= 2147483647)) {
        my_putchar('o');
        for (int i = 0; i < (nb_x -2); i++)
            my_putchar('-');
        my_putchar('o');
        middle_lines1(nb_x, nb_y);
        return (0);
    }
    else
        check_error1(nb_x, nb_y);
}