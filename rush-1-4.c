/*
** EPITECH PROJECT, 2020
** rush1-1
** File description:
** 
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}

void ft_first(int x, int y)
{
    int i;

    i = 0;
    while (i < x)
        {
        if (i == 0 && y > 1 && x > 1)
            my_putchar('A');
        if ((i == x - 1) && y > 1 && x > 1)
            my_putchar('C');
        else
            my_putchar('B');
        i = i + 1;
    }
    my_putchar('\n');
}

void ft_middle(int x, int y)
{
    int i;

    i = 0;
    while (i < x)
    {
        if (i == 0)
            my_putchar('B');
        if (i == x - 1 && x > 1)
            my_putchar('B');
        else if ( i != x - 1)
            my_putchar(' ');
        i = i + 1;
    }
    my_putchar('\n');
}

void ft_cube(int x, int y)
{
    int i;

    i = 0;
    while (i < y)
    {
        if (i == 0 || i == y - 1)
            ft_first(x, y);
        else
            ft_middle(x, y);
        i = i + 1;
    }
}

void rush(int x, int y)
{
    if(x <= 0 || y <= 0)
    {
        write(2, "Invalid size \n", 13);
        return (0);
    }
    if((x == y && x > 1 && y > 1) || x >= 4)
    {
        ft_cube(x - 1, y);
        return (0);
    }
    else
    {
        ft_cube(x, y);
        return (0);
    }
}
