/*
** EPITECH PROJECT, 2021
** continue
** File description:
** continue
*/

#include "../../include/func_name.h"

char *my_open(FILE *fd)
{
    char *map;

    map = malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++)
        map[i] = '\0';
    fread(map, 100, 1, fd);
    return (map);
}

void load_values(char *map, rpg_t *rpg)
{
    rpg->menu->main_menu->new_game->character_chosen = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->map->status = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].x =
    my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->map->pos_map[rpg->game->in_game->map->status].y =
    my_getnbr(map);
}

void load_save(rpg_t *rpg)
{
    FILE *fd = fopen("save/save.txt", "r");
    sfVector2f vect;
    char *map;

    if (fd == NULL) {
        rpg->menu->status = ON_NEW_GM;
        return;
    }
    map = my_open(fd);
    load_values(map, rpg);
    sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
    vect = put_in_vector2f(rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x, rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y);
    sfSprite_setPosition(rpg->game->in_game->map->maps
    [rpg->game->in_game->map->status], vect);
    set_player_rect(rpg);
    rpg->menu->status = ON_GAME;
    free(map);
    fclose(fd);
}