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
    int offset = 0;

    while ((len = read(fd, buffer + offset, size - offset)) > 0) {
        offset = offset + len;
    }
    if (len == -1)
        my_putstr("read failed\n");
    if (len == 0)
        my_putstr("read has nothing more to read\n");
    if (len < size && len != 0 && len != -1)
        my_putstr("read didn't complete the entire buffer\n");
    if (len == size)
        my_putstr("read completed the entire buffer\n");
}
