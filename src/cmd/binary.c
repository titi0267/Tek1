/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** path
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <dirent.h>
#include "my.h"
#include "mysh.h"

char *search_binary(char **args, shell_t *shell)
{
    char *bin = args[0];
    int len = my_strlen(bin);
    char *home;

    if (is_binary_filepath(bin, len))
        return (is_valid_binary(bin) ? my_strdup(bin) : NULL);
    else if (len >= 1 && bin[0] == '~') {
        home = get_env_value("HOME", shell->env);
        if (!home)
            return (NULL);
        bin = my_strreplace(args[0], '~', home);
        if (!is_valid_binary(bin)) {
            free(bin);
            return (NULL);
        } else
            return (bin);
    } else
        return (search_bin_in_path(args, shell));
}

char *search_bin_in_path(char **args, shell_t *shell)
{
    char *bin = NULL;
    char *env_path = get_env_value("PATH", shell->env);
    char *start = NULL;
    int len = 0;

    if (!env_path)
        return (NULL);
    for (start = env_path; *env_path; env_path += 1) {
        if (*env_path == ':') {
            if ((bin = search_binary_into_dir(args, start, len)))
                return (bin);
            start = env_path + 1;
            len = 0;
        } else
            len++;
    }
    bin = search_binary_into_dir(args, start, len);
    return (bin);
}

char *search_binary_into_dir(char **args, char *str, int len)
{
    char *bin = NULL;

    if (dir_contains_file(args[0], str, len)) {
        bin = get_binary_path(args[0], str, len);
        if (is_valid_binary(bin))
            return (bin);
        free(bin);
    }
    return (NULL);
}

char dir_contains_file(char *name, char *path, int len)
{
    char dir_path[len + 1];
    DIR *dir;
    struct dirent *file;
    int name_len = my_strlen(name);
    int ret = 0;

    my_strncpy(dir_path, path, len);
    dir = opendir(dir_path);
    if (dir == NULL)
        return (0);
    while ((file = readdir(dir))) {
        if (my_strlen(file->d_name) == name_len &&
        !my_strcmp(name, file->d_name)) {
            ret = 1;
            break;
        }
    }
    closedir(dir);
    return (ret);
}