/*
** EPITECH PROJECT, 2020
** Get Number
** File description:
** number
*/

int is_num(char const str)
{
    if (str > 47 && str < 58)
        return (1);
    else
        return (0);
}

int is_symb(char const str)
{
    if (str == '-')
        return (-1);
    else if (str == '+')
        return (1);
    else
        return (0);
}

int is_nothing(char const str)
{
    if (is_num(str) || is_symb(str) != 0)
        return (1);
    else
        return (0);
}

int calc_pos_andlim(int am_min, long num)
{
    long max_p = 2147483647;
    long min_p = -2147483648;
    if ((am_min % 2 == 0 || am_min == 0) && num <= max_p)
        return (1);
    else if ((am_min % 2 == 1) && (num * -1 >= min_p))
        return (-1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int i;
    int am_min = 0;
    long num = 0;
    char c;

    for (i = 0; is_nothing(str[i]) && str[i] != '\0'; i++) {
        c = *(str + i);
        if ((is_symb(c) == -1)) {
            am_min++;
        } else if (is_num(c)) {
            num = num * 10;
            num = num + (c - 48);
        }
        if (is_num(c) && (is_symb(str[i + 1]) != 0))
            break;
    }
    return ((int)(num * calc_pos_andlim(am_min, num)));
}
