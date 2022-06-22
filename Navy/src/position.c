/*
** EPITECH PROJECT, 2020
** position by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** position.c
*/
#include "../include/my.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

void *read_pos(pos_t *where)
{
    int read_ret1;
    int read_ret2;
    int fd_1 = open("pos1", O_RDONLY);
    int fd_2 = open("pos2", O_RDONLY);

    if (fd_1 == -1 || fd_2 == -1)
        return (NULL);
    where->pos_size = 32;
    where->pos_1 = malloc(sizeof(char) * where->pos_size + 1);
    where->pos_2 = malloc(sizeof(char) * where->pos_size + 1);
    read_ret1 = read(fd_1, where->pos_1, where->pos_size);
    read_ret2 = read(fd_2, where->pos_2, where->pos_size);
    if (read_ret1 == -1 || read_ret2 == -1)
        return (NULL);
    where->pos_1[where->pos_size] = '\0';
    where->pos_2[where->pos_size] = '\0';
    close (fd_1);
    close (fd_2);
    return (0);
}

int store_pos1(pos_t *where, int i, int l, int c)
{
    where->find_pos1[l] = malloc(sizeof(char) * 10);
    while (where->pos_1[i] != '\n') {
        where->find_pos1[l][c] = where->pos_1[i];
        c++;
        i++;
    }
    where->find_pos1[l][c] = '\n';
    where->find_pos1[l][c + 1] = '\0';
    i++;
    c = 0;
    return (i);
}

int store_pos2(pos_t *where, int i2, int l2, int c2)
{
    where->find_pos2[l2] = malloc(sizeof(char) * 10);
    while (where->pos_2[i2] != '\n') {
        where->find_pos2[l2][c2] = where->pos_2[i2];
        c2++;
        i2++;
    }
    where->find_pos2[l2][c2] = '\n';
    where->find_pos2[l2][c2 + 1] = '\0';
    i2++;
    c2 = 0;
    return (i2);
}

int store_pos(pos_t *where)
{
    int i = 0;
    int l = 0;
    int c = 0;
    int i2 = 0;
    int l2 = 0;
    int c2 = 0;

    where->find_pos1 = malloc(sizeof(char *) * 5);
    where->find_pos2 = malloc(sizeof(char *) * 5);
    while (l != 4) {
        i = store_pos1(where, i, l, c);
        i2 = store_pos2(where, i2, l2, c2);
        l2++;
        l++;
    }
    where->find_pos1[l] = NULL;
    where->find_pos2[l2] = NULL;
    return (0);
}

int print_pos(pos_t *where)
{
    read_pos(where);
    store_pos(where);
    return (0);
}
