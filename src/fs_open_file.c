/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-bsbsq-timothe.coniel
** File description:
** step_1
*/

//#include "steps.h"
#include "../include/my.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int fs_open_file(char const *filepath)
{
    int file = open(filepath, O_RDONLY);

    if (file < 0)
        return (84);
    return (file);
}