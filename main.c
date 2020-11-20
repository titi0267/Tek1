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
    //int i;
    //int o = 0;
    struct stat buff;

    stat(av[1], &buff);
    size = buff.st_size;
    //if (stat(av[1], &buff) == -1)
    //  return (NULL);
    buffer = malloc(sizeof(char) * size + 1);
    fs_understand_return_of_read(fd, buffer, size);
    //carac_on_line(buffer, info);
    //i = 0;
    //calc(buffer, i, info);
    find_square(buffer, info);
    my_putstr("OU CA DEMARRE : ");
    my_put_nbr(info->where);
    //my_put_nbr(i);
    //my_putchar(buffer[104]);
    //my_putchar(buffer[104 - 98]);
    my_putchar('\n');
    my_putstr("DE QUEL TAILLE : ");
    my_put_nbr(info->big);
    //buffer[9] = buffer[9] + buffer[10] - 48 - 48;
    my_putchar('\n');
    //my_put_nbr(buffer[9]);
    //my_putchar('\n');
    //my_putchar(buffer[100]);
    //my_putchar(buffer[13]);
    //my_put_nbr(info->carac_l);
    write(1, buffer, size);
    close(fd);
    free(buffer);
    return (0);
}