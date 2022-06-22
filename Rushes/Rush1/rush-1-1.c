/*
** EPITECH PROJECT, 2020
** rush-1-1
** File description:
** 
*/

void up_down(int x, int y)
{
    int i;

    for (i = 0; i < x; i = i + 1) {
        if(i == 0 || i == x - 1)
            my_putchar('o');
        else
            my_putchar('-');
    }

}

void space(int x, int y)
{
    for (int m = 1; m < x - 1; m = m + 1) {
            my_putchar(' ');
    }
}
void side(int x, int y)
{
    int j;

    my_putchar('\n');
    for (j = 1; j < y - 1; j = j + 1) {
        my_putchar('|');
        space(x, y);
        my_putchar('|');
        my_putchar('\n');
    }
}

void rush(int x, int y)
{
    if (y <= 0 && x <= 0)
        return ('Invalid_size\n');
    else if (x == 1 || y == 1) {
        my_putchar('o');
        my_putchar('\n');
    }
    else {
    up_down(x, y);
    side(x, y);
    up_down(x, y);
    }
}