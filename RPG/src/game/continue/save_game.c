/*
** EPITECH PROJECT, 2021
** header
** File description:
** save_game
*/

#include "../../../include/func_name.h"

static char *save_char(new_game_t *newgame)
{
    char *character = "";
    character = my_strcat(my_strcat(character,
    my_putnbr(newgame->character_chosen)), ";");

    return (character);
}

static char *save_pos(rpg_t *rpg)
{
    char *pos = "";

    pos = my_strcat(pos, my_strcat(my_strcat(
    my_putnbr(rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x), ";"),
    my_strcat(my_putnbr(rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y), ";")));
    pos = my_strcat(pos, my_strcat(my_putnbr((int)rpg->game->in_game->
    objects->car->car_pos.x), my_strcat(my_strcat(";", my_putnbr(
    (int)rpg->game->in_game->objects->car->car_pos.y)), ";")));
    pos = my_strcat(pos, my_strcat(my_putnbr
    (rpg->game->in_game->objects->car->last_dir), ";"));
    pos = my_strcat(pos, my_strcat(my_putnbr
    (rpg->game->in_game->objects->car->top_car), ";"));
    pos = my_strcat(pos, my_strcat(my_putnbr
    (rpg->game->in_game->map->car_map), ";"));
    return (pos);
}

static char *save_on_map(rpg_t *rpg)
{
    char *on_map = "";
    on_map = my_strcat(on_map, my_strcat(
    my_putnbr(rpg->game->in_game->map->status), ";"));

    return (on_map);
}

void save_map(rpg_t *rpg)
{
    FILE *fd = fopen("save/save.txt", "w");
    char *save = save_char(rpg->menu->main_menu->new_game);
    char *pos = save_pos(rpg);
    char *map = save_on_map(rpg);
    char *stats = save_stats(rpg);
    char *advanc = save_avance(rpg);
    char *invent = save_invent(rpg);

    save = my_strcat(save, my_strcat(map, my_strcat(pos, my_strcat (stats,
    my_strcat(advanc, invent)))));
    fwrite(save, 1, my_strlen(save), fd);
    free(save);
    free(pos);
    free(map);
    fclose(fd);
}