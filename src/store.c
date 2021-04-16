/*
** EPITECH PROJECT, 2021
** Map by Timothy CONIEL & Tom NOMINE
** File description:
** map.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int store_words(duo_stp_t *map)
{
    int i = 0;
    int d = 0;
    int c = 0;

    map->line = malloc(sizeof(char *) * (map->line_nbr + 1));
    while (d != map->line_nbr) {
        map->line[d] = malloc(sizeof(char) * (map->char_nbr + 1));
        while (map->buffer[i] != '\n') {
            map->line[d][c] = map->buffer[i];
            c++;
            i++;
        }
        map->line[d][c] = '\0';
        i++;
        d++;
        c = 0;
    }
    map->line[d] = NULL;
    return (0);
}
