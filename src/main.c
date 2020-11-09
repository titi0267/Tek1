/*
** EPITECH PROJECT, 2020
** PRINTF
** File description:
** main
*/

#include "../include/my.h"
#include <stdarg.h>
void print_char(va_list *);
void print_str(va_list *);

int find_flag(char *flag_board, char flag_char)
{
    int flag_nbr = 0;

    for (; flag_board[flag_nbr] != 0; flag_nbr ++) {
        if (flag_board[flag_nbr] == flag_char)
            return (flag_nbr);
    }
    return (-1);
}

void my_printf(char *str, ...)
{
    void (*functionName[2]) (va_list *) = {print_str, print_char};
    char flag_board[3] = {'s', 'c', 0};
    va_list argu_list;
    int flag_nbr = 0;

    va_start(argu_list, str);
    for (int arr = 0; str[arr] != 0; arr ++) {
        if (arr != 0 && str[arr - 1] == '%') {
            flag_nbr = find_flag(flag_board, str[i]);
            if (flag_nbr != -1)
                (*functionName[flag_nbr]) (argu_list);
        } else if (str[arr] != '%') {
            write(1, &str[arr], 1);
        }
    }
}

int main(void)
{
    my_printf("%c would %s an ice-cream %s %c banana !\n", 'I', "like", "and", 'a');
}