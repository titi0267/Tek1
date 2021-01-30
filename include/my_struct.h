/*
** EPITECH PROJECT, 2020
** My_structure by Timothy CONIEL
** File description:
** my_struct.h
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct my_struct_s
{
    pid_t process_id1;
    pid_t process_id2;
    char *str;
    char **cmd;
    int cmd_flags;
    int *flag_len;
    char **flags;
    char **cmd_path;
    char *cd_pwd;
    char **bin_path;
    char **bin_cat;
    char **find_cmd;
    int cmd_nbrp;
    char *keep_alph;
    char *pwd;
} my_struct_t;

#endif /* !MY_STRUCT_H_ */
