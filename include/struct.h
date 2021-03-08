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
    int lines_tot;
    int line_nbr;
    int match_max;
} map_t;

typedef struct user_s
{
    int line;
    int matches;
    char *str;
    int turn;
    int lose;
} user_t;

typedef struct ai_s
{
    int line;
    int matches;
    int matches_to_rm;
    int line_chosen;
    int lose;
} ai_t;

typedef struct core_s
{
    map_t *map;
    user_t *user;
    ai_t *ai;
} core_t;

#endif /* !struct_header */
