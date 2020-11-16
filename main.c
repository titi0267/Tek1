/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** main
*/

#include "include/my.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int fd = fs_open_file(av[1]);
    int size;
    char *buffer;
    int x = 0;

    buffer = malloc(sizeof(char) * size + 1);
    fs_understand_return_of_read(fd, buffer, size);
    fs_cat_x_bytes(fd, buffer, size);
    write(1, buffer, size);
    close(fd);
}