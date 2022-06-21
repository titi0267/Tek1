/*
** EPITECH PROJECT, 2020
** B-PSU-100-STG-1-1-myls-timothe.coniel
** File description:
** error
*/
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"

int is_dir(char *dir_name, result_t *data)
{
    int i = 0;
    struct dirent *dir;
    DIR *open_dir = opendir(dir_name);
    data->name = malloc(sizeof(char **) * 1000);

    if (open_dir == NULL) {
        disp_error("file or directory does not exist");
        return (84);
    }
    while ((dir = readdir(open_dir)) != NULL) {
        data->name[i] = malloc(sizeof(char *) * my_strlen(dir->d_name));
        data->name[i] = dir->d_name;
        my_putstr(data->name[i]);
        my_putchar('\n');
        i++;
    }
    data->name[i] = 0;
    closedir(open_dir);
}

void init_flag(result_t *data)
{
    data->flag_R[0] = 'g';
    data->flagt [0]= 'g';
    data->flag_l[0] = 'g';
    data->flag_d[0] = 'g';
    data->flag_r[0] = 'g';
}

int is_flag(char *av, result_t *data)
{
    int i = 0;

    for (; av[i] != '\0'; i++) {
        if (av[i] == 'l') {
            data->flag_l[0] = 'l';
        }
        else if (av[i] == 'R')
            data->flag_R[0] = 'R';
        else if (av[i] == 'r')
            data->flag_r[0] = 'r';
        else if (av[i] == 't')
            data->flagt[0] = 't';
        else if (av[i] == 'd')
            data->flag_d[0] = 'd';
        else
            return (-1);
    }
    return (0);
}

int arg_doubled_begin(char **av, result_t *data)
{
    int temp_error = 0;

    for (int i = 0; av[i] != 0; i++) {
        for (int j = 0; av[i][j] != '\0'; j++) {
            if (av[i][0] == '-')
                temp_error = is_flag(av[i], data);
            if (temp_error == -1)
                return (-1);
            //if (av[i][0] != '-' || (av[i][j] == '-' && j > 0)
            //    data->ckech_file = function(av[i], data);
        }
    }
}

int my_ls(char **av, result_t *data)
{
    //int x = 0;
    for (int i = 0; av[i]; i++) {
        is_dir(av[i], data);
        arg_doubled_begin(av, data);
    }

}

int main(int ac, char **av)
{
    result_t data;

    my_ls(av, &data);
}