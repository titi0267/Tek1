/*
** EPITECH PROJECT, 2021
** header
** File description:
** save_game
*/

#include "../../../include/func_name.h"

char *save_char(new_game_t *newgame)
{
    char *character = "";
    character = my_strcat(my_strcat(character,
    my_putnbr(newgame->character_chosen)), ";");

    return (character);
}

char *save_pos(map_t *map)
{
    char *pos = "";
    pos = my_strcat(pos, my_strcat(my_strcat(
    my_putnbr(map->pos_map[map->status].x), ";"),
    my_strcat(my_putnbr(map->pos_map[map->status].y), ";")));

    return (pos);
}

char *save_on_map(map_t *map)
{
    char *on_map = "";
    on_map = my_strcat(on_map, my_strcat(
    my_putnbr(map->status), ";"));

    return (on_map);
}

void save_map(rpg_t *rpg)
{
    FILE *fd = fopen("save/save.txt", "w");
    char *save = save_char(rpg->menu->main_menu->new_game);
    char *pos = save_pos(rpg->game->in_game->map);
    char *map = save_on_map(rpg->game->in_game->map);
    char *stats = save_stats(rpg);
    char *advanc = save_avance(rpg);

    save = my_strcat(save, my_strcat(map, my_strcat(pos, my_strcat (stats,
    advanc))));
    fwrite(save, 1, my_strlen(save), fd);
    free(save);
    free(pos);
    free(map);
    fclose(fd);
}