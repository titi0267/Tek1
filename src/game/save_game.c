/*
** EPITECH PROJECT, 2021
** header
** File description:
** save_game
*/

#include "../../include/func_name.h"

char *save_char(new_game_t *newgame)
{
    char *character = "CHARACTER=";
    character = my_strcat(my_strcat(character,
    my_putnbr(newgame->character_chosen)), "\n");

    return (character);
}

char *save_pos(map_t *map)
{
    char *pos = "POSITION=";
    pos = my_strcat(pos, my_strcat(my_strcat(
    my_putnbr(map->pos_map[map->status].x), ";"),
    my_strcat(my_putnbr(map->pos_map[map->status].y), "\n")));

    return (pos);
}

char *save_map_on(map_t *map)
{
    char *map_on = "MAP=";
    map_on = my_strcat(map_on, my_strcat(my_putnbr(map->status), "\n"));

    return (map_on);
}

char *save_invent(void)
{
    char *invent = "INVENTORY=";
    invent = my_strcat(invent, my_strcat(my_putnbr(0), "\n"));

    return (invent);
}

void save_map(rpg_t *rpg)
{
    FILE *fd = fopen("save/save.txt", "w");
    char *save = save_char(rpg->menu->main_menu->new_game);
    char *pos = save_pos(rpg->game->in_game->map);
    char *map = save_map_on(rpg->game->in_game->map);
    char *invent = save_invent();
    char* advanc = "ADVANCEMENT=";

    save = my_strcat(save, my_strcat(pos, my_strcat(map, my_strcat (invent,
    advanc))));
    fwrite(save, 1, my_strlen(save), fd);
    free(save);
    free(pos);
    free(map);
    fclose(fd);
}