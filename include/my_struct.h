/*
** EPITECH PROJECT, 2020
** my_struct for the infin_add.c project by Elliot WALDVOGEL
** File description:
** my_struct
*/

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct infin_number
{
    int amount;
    pid_t process_id1;
    pid_t process_id2;
} infin_number_t;

#endif /* !MY_STRUCT_H_ */