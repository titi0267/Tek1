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
    char *buffer;// = malloc(sizeof(char) * size);
    //int x = 0;
    //int w = 0;
    buffer_size_t *info = malloc(sizeof(buffer_size_t));
    struct stat buff;

    fstat(fd, &buff);
    size = buff.st_size;
    buffer = malloc(sizeof(char) * size + 1);
    fs_understand_return_of_read(fd, buffer, size);
    //for (int i = 0; buffer[i] != '\0'; i++) {
    dot_pos(buffer, info);
    //}
    my_put_nbr(info->store_btw);
    my_putchar('\n');
    my_put_nbr(info->store_nbrbuf);
    my_putchar('\n');
    //my_put_nbr(info->store_nbrline);
    //my_putchar('\n');
    my_put_nbr(info->carac_l);
    my_putchar('\n');
    my_put_nbr(info->before_n);
    my_putchar('\n');
    my_put_nbr(info->after_n);
    my_putchar('\n');
    write(1, buffer, size);
    //my_putchar(buffer[19]);
    //my_putstr(buffer);
    close(fd);
    //printf("%d\n", info->store_btw);
}