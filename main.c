/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** main
*/
#include "include/steps.h"
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
    buffer_size_t *info = malloc(sizeof(buffer_size_t));
    struct stat buff;

    stat(av[1], &buff);
    size = buff.st_size;
    //if (stat(av[1], &buff) == -1)
    //  return (NULL);
    buffer = malloc(sizeof(char) * size + 1);
    fs_understand_return_of_read(fd, buffer, size);
    //calc(buffer, info);
    //my_putchar('\n');
    //my_putchar(buffer[2]);
    //my_putchar(buffer[3]);
    //my_putchar(buffer[100]);
    //my_putchar(buffer[13]);
    //my_put_nbr(info->carac_l);
    write(1, buffer, size);
    close(fd);
    free(buffer);
    return (0);
}