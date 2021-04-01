/*
** EPITECH PROJECT, 2020
** Map by Timothy CONIEL & Tom NOMINE
** File description:
** map.c
*/

#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>

int open_file(duo_stp_t *duo)
{
    int i = 0;
    duo->fd = malloc(sizeof(int) * duo->len);

    for (; duo->nbrs[i] != NULL; i++) {
        duo->fd[i] = open(duo->nbrs[i], O_RDONLY);
        if (duo->fd[i] == -1)
            return (84);
        else
            read_map(duo, i);                                                     
    }
    duo->fd[i] = -1;
}

int cp_nbr(duo_stp_t *duo, int y)
{
    duo->store[y] = malloc(sizeof(char) * my_strlen(duo->buffer) + 1);

    if (duo->store[y] == NULL)
        return (84);
    for (int i = 0; duo->buffer[i] != '\0'; i++)
        duo->store_buf[y][i] = duo->buffer[i];
    return (0);
}

int read_map(duo_stp_t *map, int i)
{
    int read_ret;

    map->buffer_size = 1800;
    map->buffer = malloc(sizeof(char) * map->buffer_size + 1);
    if (map->buffer == NULL)
        return (84);
    read_ret = read(fd, map->buffer, map->buffer_size);
    if (read_ret == -1) {
        write(2, "wrong read\n", 12);
        return (84);
    }
    map->buffer_size = read_ret;
    map->buffer[map->buffer_size] = '\0';
    if (cp_nbr(duo, i) == 84)
        return (84);
    close(fd[i]);
    return (0);
}
