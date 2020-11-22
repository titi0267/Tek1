/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-bsbsq-timothe.coniel
** File description:
** step_1
*/

//#include "steps.h"
#include "../include/my.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

char *fs_understand_return_of_read(char *filepath, buffer_size_t *info)
{
    struct stat buff;
    char *str = NULL;
    int fd = open(filepath, O_RDONLY);
    ssize_t read_ret = 0 ;

    if (fd == -1 || stat(filepath, &buff) == -1)
        return (NULL);
    str = malloc(sizeof(char) * (buff.st_size + 1));
    if (str == NULL)
        return (NULL);
    read_ret = read(fd, str, buff.st_size);
    if (read_ret == - 1)
        return (NULL);
    str[buff.st_size] = '\0' ;
    info->j = malloc(sizeof(int) * (buff.st_size + 1));
    close(fd);
    return (str);
}
