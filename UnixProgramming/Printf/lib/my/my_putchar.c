/*
** EPITECH PROJECT, 2020
<<<<<<< HEAD
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** my_putchar
*/
#include "my_struct.h"
#include <unistd.h>
#include "my.h"

void my_putchar(char c, str_len_t *info)
{
    info->buf_size++;
    write(1, &c, 1);
}
=======
** my_putchar.c by Elliot WALDVOGEL
** File description:
** my_putchar
*/

void my_putchar(char c)
{
    write(1, &c, 1);
}
>>>>>>> FinalStumper
