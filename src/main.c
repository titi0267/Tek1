/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myrunner-timothe.coniel
** File description:
** test
*/
#include "../include/my.h"
#include "../include/my_struct.h"

int main(void)
{
    map_t *buff = malloc(sizeof(map_t));
    print_map(buff);
    for (int i = 0; i != 11; i++)
        free(buff->line[i]);
    free(buff->line);
    free(buff->buffer);
    free(buff);
}