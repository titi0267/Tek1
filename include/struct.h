/*
** EPITECH PROJECT, 2021
** struct by Timothy CONIEL & Tristan HOURTOUILLE
** File description:
** struct.h
*/

#ifndef struct_header
#define struct_header
#include "matchstick.h"
#define ERROR 84
#define TRUE 1
#define FALSE 0

typedef struct map_s
{
    char **map;
    int car_nbr;
    int lines;
} map_t;

typedef struct user_s
{
    int line;
    int matches;
    char *str;
} user_t;

#endif /* !struct_header */
