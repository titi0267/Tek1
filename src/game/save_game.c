/*
** EPITECH PROJECT, 2021
** header
** File description:
** save_game
*/

#include "../../include/func_name.h"

void save_map(rpg_t *rpg)
{
    FILE *fd = fopen("save/save.txt", "w");
    char *save = my_strcat(my_strcat("CHARACTER=",
    my_putnbr(rpg->menu->main_menu->new_game->character_chosen)), "\n");
    char *pos = my_strcat("POSITION=", my_strcat(my_strcat(
    my_putnbr(rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x), ";"), my_strcat(my_putnbr(rpg->game->
    in_game->map->pos_map[rpg->game->in_game->map->status].y), "\n")));
    char *map = my_strcat("MAP=", my_putnbr(rpg->game->in_game->map->status));

    save = my_strcat(save, my_strcat(pos, map));
    fwrite(save, 1, my_strlen(save), fd);
    fclose(fd);
}