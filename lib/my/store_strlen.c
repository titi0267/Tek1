/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myprintf-timothe.coniel
** File description:
** store_strlen
*/
#include "my.h"
#include "my_struct.h"

int store_vlen(int v, str_len_t *info)
{
    v = info->buf_size;
    //printf("%d\n", v);
    return (0);
}

/*void disp_len(int v, str_len_t *info)
{
    int v = store_len(v, info)
    if ()
}*/

void store_len(va_list *argu_list, str_len_t *info)
{
        int v = va_arg(*argu_list, int);

        int x = info->buf_size;
}