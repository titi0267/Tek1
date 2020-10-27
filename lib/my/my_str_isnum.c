/*
** EPITECH PROJECT, 2020
** hh
** File description:
** hh
*/

int my_rodlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}

static int check_nums(char c)
{
    if ((c >= '0') && (c <= '9')) {
        return (1);
    }
    return (0);
}
int my_str_isnum(char const *str)
{
    for (int i = 0; i < my_rodlen(str); i++) {
        if (!check_nums(str[i])) {
            return (0);
        }
    }
    return (1);
}