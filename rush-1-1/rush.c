/*
** EPITECH PROJECT, 2020
** rush-1-1
** File description:
** 
*/

int my_putstr(char const *str)
{
    char carac;

    carac = 0;
    while (str[carac] != '\0' ) {
        my_putchar(str[carac]);
        carac++;
    }
    return (str);
}

void first_line(int x, int y)
{
    my_putchar('o');
    for (int i = 0; i <= x - 2; i = i + 1)
        my_putchar('-');
    my_putchar('o');
}

void middle(int x, int y)
{
    for (int i = 0; i < y - 1; i = i + 1) {
        my_putchar('\n');
        my_putchar('|');
        for (int j = 0; j <= x - 2; j = j + 1) {
            my_putchar(' ');
        }
        my_putchar('|');
    }
    my_putchar('\n');
}

void rush(int x, int y)
{
    if (y <= 0 && x <= 0)
        my_putstr("Invalid_size\n");
    else if (x == 1 && y == 1) {
        my_putchar('o');
        my_putchar('\n');
    } else {
        first_line(x, y);
        middle(x, y);
        first_line(x, y);
    }
}