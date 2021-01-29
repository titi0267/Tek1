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
    char *str;
    char **cmd;
    int cmd_flags;
    int *flag_len;
    char **flags;
    char *cd_pwd;
    char *cmd_path;
} my_struct_t;

#endif /* !MY_STRUCT_H_ */
