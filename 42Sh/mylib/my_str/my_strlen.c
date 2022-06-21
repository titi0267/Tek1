/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** return length of a string
*/

int my_strlen(char const *str)
{
    int length = 0;

    while (str[length] != '\0')
        length++;
    return (length);
}

int my_get_biggest_line(char const *str)
{
    int biggest = 0;
    int actual = 0;

    for (; *str; str += 1) {
        if (*str == '\n') {
            if (actual > biggest)
                biggest = actual;
            actual = 0;
            continue;
        }
        actual++;
    }
    return (biggest == 0 ? actual : biggest);
}
