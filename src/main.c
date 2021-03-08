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
    for (int i = 0; core->map->map[i] != NULL; i++)
        my_printf("%s", core->map->map[i]);
}

int main(int ac, char **av)
{
    int lose = 0;
    core_t *core = malloc(sizeof(core_t));

    if (core == NULL || malloc_struct(core) == ERROR ||
        error_wrong_arg(ac, av) == ERROR ||
        map_created(core->map, av) == ERROR) {
        my_puterr("exit 84\n");
        return (ERROR);
    }
    init_game(core, av);
    if (main_loop(core) == 1)
        return (0);
    lose = who_lost(core);
    if (lose == 0)
        free_struct(core);
    else
        return (lose);
    return (0);
}
