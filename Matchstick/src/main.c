/*
** EPITECH PROJECT, 2021
** main by Timothy CONIEL
** File description:
** main for matchstick project
*/

#include "../include/matchstick.h"

int malloc_struct(core_t *core)
{
    core->map = malloc(sizeof(map_t));
    core->user = malloc(sizeof(user_t));
    core->ai = malloc(sizeof(ai_t));

    if (core->map == NULL || core->user == NULL || core->ai == NULL)
        return (ERROR);
    return (0);
}

void free_struct(core_t *core)
{
    for (int i = 0; core->map->map[i] != NULL; i++)
        free(core->map->map[i]);
    free(core->map->map);
    free(core->user->str);
    free(core->ai);
    free(core->user);
    free(core->map);
    free(core);
}

void init_game(core_t *core, char **av)
{
    core->ai->line = my_getnbr(av[1]);
    core->ai->matches = my_getnbr(av[2]);
    core->user->lose = FALSE;
    core->ai->lose = FALSE;
    for (int i = 0; core->map->map[i] != NULL; i++) {
        for (int c = 0; core->map->map[i][c] != '\0'; c++)
            my_printf("%c", core->map->map[i][c]);
    }
}

int main(int ac, char **av)
{
    int lose = 0;
    core_t *core = malloc(sizeof(core_t));

    if (core == NULL || malloc_struct(core) == ERROR ||
        error_wrong_arg(ac, av) == ERROR ||
        map_created(core->map, av) == ERROR) {
        return (ERROR);
    }
    init_game(core, av);
    if (main_loop(core) == 1) {
        free_struct(core);
        return (0);
    }
    lose = who_lost(core);
    if (lose == 0)
        free_struct(core);
    else
        return (lose);
    return (0);
}
