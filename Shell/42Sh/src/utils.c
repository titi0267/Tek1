/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** utils
*/

#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "my.h"
#include "mysh.h"

/*
**allocates one more memory and appends a char at the end of a char*
**!danger you are responsible for putting a
*/
void add_char(char **str, int len, char c)
{
    char *new_str = malloc(sizeof(char) * (len + 1));

    if (!new_str)
        return;
    my_strncpy(new_str, *str, len);
    new_str[len] = c;
    free(*str);
    *str = new_str;
}

int count_char(char *str, char c)
{
    int nb = 0;

    for (; *str; str++) {
        if (*str == c)
            nb++;
    }
    return (nb);
}

void free_array(char **array)
{
    for (char **elem = array; elem != 0; elem++)
        free(elem);
    free(*array);
}

void print_err(char *str)
{
    my_putstr(2, str);
    write(2, ": ", 2);
    my_putstr(2, strerror(errno));
    write(2, ".\n", 2);
}

int str_to_int(char *str)
{
    int value = 0;

    for (; *str; str++) {
        if (*str < '0' || *str > '9')
            return (-1);
        value = value * 10 + (*str - '0');
    }
    return (value);
}