/*
** EPITECH PROJECT, 2020
** my_put_character_printf by Timothy CONIEL
** File description:
** my_putcharp.c
*/
#include "myp.h"

void my_putcharp(char c, str_len_t *info)
{
    info->buf_size++;
    write(1, &c, 1);
}
