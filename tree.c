/*
** EPITECH PROJECT, 2020
** tree
** File description:
** 
*/
void print_leaves(int end_space, int end_stars)
{
    for (int a = 0; a <= end_space; a = a + 1)
        my_putchar(' ');
    for (int b = 0; b != end_stars; b = b + 1)
        my_putchar('*');
    my_putchar('\n');
}

void print_trunc(int end_space, int end_trunk)
{
    for (int a = 0; a <= end_space; a = a + 1)
        my_putchar(' ');
    for (int b = 0; b != end_trunk; b = b + 1)
        my_putchar('|');
    my_putchar('\n');
}

void leaves(int end_space, int size)
{
    int a = 0;
    int height = 4;
    int end_stars = 1;

    for (int b = 0; b != size; b = b + 1, height = height + 1) {
        for (int c = 0; c != height; c += 1, end_space -= 1, end_stars += 2)
            print_leaves(end_space ,end_stars);
        if (b % 2 == 0 && b != 0)
            a = a + 2;
        end_stars = end_stars - 4 - a;
        end_space = end_space + 2 + a / 2;
    }
}

void trunc(int length, int width)
{
    int end_space;
    int end_trunk = width;

    if (end_trunk % 2 == 0)
        end_trunk = end_trunk + 1;
    end_space = length - end_trunk / 2;
    for (int a = 0; a != width; a = a + 1)
        print_trunc(end_space, end_trunk);
}

void tree(int size)
{
    int b = 0;
    int lenght = 0;

    if (size == 0)
        return (0);
    for (int a = 0; a < size; a = a + 1) {
        b = b + 1;
        lenght = lenght + 1 + b;
    }
    leaves(lenght, size);
    trunc(lenght, size);
}