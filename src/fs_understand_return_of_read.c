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

void fs_understand_return_of_read(int fd, char *buffer, int size)
{
    int len;

    len = read(fd, buffer, size);
    buffer[size] = '\0';
}
