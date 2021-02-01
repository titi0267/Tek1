/*
** EPITECH PROJECT, 2020
** my_functions by Timothy CONIEL
** File description:
** my.h
*/

#define _XOPEN_SOURCE 700
#ifndef MY_H_
#define MY_H_
#include "../lib/my/printf/myp.h"
#include "../lib/my/my.h"
#include "my_struct.h"

//#include <sys/types.h>
#include <sys/wait.h>
//#include <signal.h>
#include <stdio.h>
#include <unistd.h>
//#include <dirent.h>

void my_putchar(char c);
int my_putstr(char const *str);
int my_strncmp(char *cmp, char *cmpd);
int my_putnbr(int nb);
int my_getnbr(char *str);
char *my_int_str(int nb, lib_t *lib);
int my_strlen(char *str);
int my_printf(char *str, ...);
void my_count_word(my_struct_t *info);
int shell(my_struct_t *info);
int cd(my_struct_t *info, char **env);
char *keep_alpha(my_struct_t *info);
int my_unsetenv(my_struct_t *info, char **env);
void store_env(my_struct_t *info, char **env);
int search(my_struct_t *info, char **env);
int envi(my_struct_t *info, char **env);
int my_setenv(my_struct_t *info, char **env);
int alrd_setenv(my_struct_t *info, int x);
int exit_shell(my_struct_t *info, char **env);
int ptr_arr(my_struct_t *info, char **env);
int create_env(my_struct_t *info);
void store_tempenv(my_struct_t *info);

#endif /* !MY_H_ */
