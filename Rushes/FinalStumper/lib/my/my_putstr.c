/*
** EPITECH PROJECT, 2020
<<<<<<< HEAD
** B-CPE-100-STG-1-1-cpoolday04-timothe.coniel
** File description:
** my_putstr
*/
#include "my.h"
#include "my_struct.h"

int my_putstr(char const *str, str_len_t *info)
{
    int carac;

    carac = 0;
    while (str[carac] != '\0' ) {
        my_putchar(str[carac], info);
        carac++;
    }
=======
** my_putstr.c by Elliot WALDVOGEL
** File description:
** my_putstr
*/

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        my_putchar(str[i]);
>>>>>>> FinalStumper
    return (0);
}