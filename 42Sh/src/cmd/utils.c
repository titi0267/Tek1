/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** command utils
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include "my.h"
#include "mysh.h"

char is_binary_filepath(char *bin, int len)
{
    return (len >= 3 && bin[0] == '.' && bin[1] == '.' && bin[2] == '/') ||
    (len >= 2 && bin[0] == '.' && bin[1] == '/') || (len >= 1 && bin[0] =='/');
}

char is_valid_binary(char *path)
{
    struct stat statbuf;

    if (stat(path, &statbuf) == -1)
        return (0);
    if (!S_ISREG(statbuf.st_mode)) {
        errno = 13;
        return (0);
    }
    return (access(path, X_OK) == -1 ? 0 : 1);
}

char *get_binary_path(char *name, char *start, int len)
{
    char dir[len + 1];
    char *bin_path = NULL;

    my_strncpy(dir, start, len);
    bin_path = my_strmerge(dir, name);
    my_strinsert(&bin_path, "/", len);
    return (bin_path);
}

int change_dir(char *dir, shell_t *shell)
{
    int ret = chdir(dir);
    char path[256];
    char *prev_dir;

    if (ret == -1)
        print_err(dir);
    else {
        getcwd(path, 256);
        prev_dir = my_strdup(get_env_value("PWD", shell->env));
        set_variable("PWD", path, shell->env);
        if (shell->prev_cd)
            free(shell->prev_cd);
        shell->prev_cd = prev_dir;
        set_variable("OLDPWD", prev_dir, shell->env);
    }
    return (ret);
}
