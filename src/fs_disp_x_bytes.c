/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-bsbsq-timothe.coniel
** File description:
** fs_disp_x_bytes
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void  fs_cat_x_bytes(int fd, char *buffer, int size)
{
    struct stat buff;

    fstat(fd, &buff);
    size = buff.st_size;
}