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
    int process_id;
    char *str;
    char **cmd;
    int cmd_flags;
    int *flag_len;
    char **ls_args;
} my_struct_t;

#endif /* !MY_STRUCT_H_ */
