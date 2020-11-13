/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** store_strlen
*/
#include "my.h"
#include "my_struct.h"

void store_len(va_list *argu_list, str_len_t *info)
{
        int x = 0;

        x = info->buf_size;
        my_put_nbr(x, info);
}