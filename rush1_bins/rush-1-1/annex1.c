/*
** EPITECH PROJECT, 2020
** annex-1.c by Elliot WALDVOGEL
** File description:
** annex
*/

void my_putchar(char c)
{
    write (1, &c, 1);
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
}

int special_cases1(char **av)
{
    for (int i = 0; av[1][i] != '\0'; i++) {
        if (av[1][i] < 48 || av[1][i] > 57) {
            my_putstr("Invalid size\n");
            return (84);
        }
    }
    for (int i = 0; av[2][i] != '\0'; i++) {
        if (av[2][i] < 48 || av[2][i] > 57) {
            my_putstr("Invalid size\n");
            return (84);
        }
    }
}

int determine1(char *str)
{
    int a = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        a += str[i] - 48;
        if (str [i + 1] != '\0')
            a *= 10;
    }
    return (a);
}

int main(int ac, char **av)
{
    int a;
    int b;

    if (ac != 3) {
        my_putstr("Invalid size\n");
        return (84);
    }
    a = av[1][0] - 48;
    b = av[2][0] - 48;
    a = determine1(av[1]);
    b = determine1(av[2]);
    if (special_cases1(av) == 84) {
        return (84);
    }
    rush(a, b);
    my_putchar('\n');
    return (0);
}