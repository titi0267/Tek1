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
    duo->store_buf = malloc(sizeof(char *) * duo->len + 1);

    for (; duo->nbrs[i] != NULL; i++) {
        duo->fd[i] = open(duo->nbrs[i], O_RDONLY);
        if (duo->fd[i] == -1)
            return (84);
        else
            read_map(duo, i);
    }
    duo->nbrs[i] = NULL;
    duo->fd[i] = -1;
}

int cp_nbr(duo_stp_t *duo, int i)
{
    int d = 0;
    duo->store_buf[i] = malloc(sizeof(char) * my_strlen(duo->buffer) + 1);

    if (duo->store_buf[i] == NULL)
        return (84);
    for (; duo->buffer[d] != '\0'; d++)
        duo->store_buf[i][d] = duo->buffer[d];
    duo->store_buf[i][d] = '\0';
    return (0);
}

int read_map(duo_stp_t *duo, int i)
{
    int read_ret;

    duo->buffer_size = 31;
    duo->buffer = malloc(sizeof(char) * duo->buffer_size);
    if (duo->buffer == NULL)
        return (84);
    read_ret = read(duo->fd[i], duo->buffer, duo->buffer_size);
    if (read_ret == -1) {
        write(2, "wrong read\n", 12);
        return (84);
    }
    printf("read = %i\n", read_ret);
    duo->buffer_size = read_ret;
    duo->buffer[duo->buffer_size] = '\0';
    if (cp_nbr(duo, i) == 84)
        return (84);
    close(duo->fd[i]);
    return (0);
}
