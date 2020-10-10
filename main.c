/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-rush2-lilou.stoll-metz
** File description:
** main
*/

int find_char(char *str, char c, char c2)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c || str[i] == c2)
            count += 1;
    }
    return (count);
}

int display_count(char *str, char c)
{
    char c2;

    if (c >= 'A' && c <= 'Z')
        c2 = c + 32;
    else if (c >= 'a' && c <= 'z')
        c2 = c - 32;
    else
        return (84);
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(find_char(str, c, c2));
    my_putchar(' ');
    my_putchar('(');
    print_float("%.2f",find_frequency(str, c));
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
    return (0);
}

int main (int ac, char **av)
{
    char *str = av[1];

    for(int i = 2; i < ac; i += 1) {
        if (display_count(str, av[i][0]) == 84) {
            write(2, "Not a char", 10);
            my_putchar('\n');
            return (84);
        }
    }
    return (0);
}