/*
** EPITECH PROJECT, 2021
** continue
** File description:
** continue
*/

#include "../../../include/func_name.h"

char *my_open(FILE *fd)
{
    char *map;

    map = malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++)
        map[i] = '\0';
    fread(map, 100, 1, fd);
    return (map);
}

static void load_inventory(char *map, rpg_t *rpg)
{
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->inventory->area_contains[WEAPON] = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->inventory->area_contains[VEST] = my_getnbr(map);
    for (int i = 0; i <= TAZER; i++) {
        for (; map[0] != ';'; map++);
        map++;
        rpg->game->in_game->stuff->stuff_status[i] = my_getnbr(map);
    }
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stuff->stuff_status[BPVEST] = my_getnbr(map);
    if ( rpg->game->in_game->stuff->stuff_status[BPVEST] == TRUE)
        rpg->game->in_game->inventory->area_contains[VEST] = TRUE;

}

static void load_value2(char *map, rpg_t *rpg)
{
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stats->level = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->stats->xp_value = my_getnbr(map);
    for (int i = 0; i <= P_ARMOR; i++) {
        for (; map[0] != ';'; map++);
        map++;
        rpg->game->in_game->stats->player_stats[i]->base_value = my_getnbr(map);
    }
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->phone->notif_index = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->game_status = my_getnbr(map);
    load_inventory(map, rpg);
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
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->objects->car->car_pos.x = my_getnbr(map);
    for (; map[0] != ';'; map++);
    map++;
    rpg->game->in_game->objects->car->car_pos.y = my_getnbr(map);
    load_value2(map, rpg);
}

void set_loaded_value(rpg_t *rpg)
{
    sfVector2f vect;

    vect = put_in_vector2f(rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].x, rpg->game->in_game->map->pos_map
    [rpg->game->in_game->map->status].y);
    sfSprite_setPosition(rpg->game->in_game->map->maps
    [rpg->game->in_game->map->status], vect);
    set_player_rect(rpg);
    rpg->game->in_game->phone->notif_prev =
    rpg->game->in_game->phone->notif_index;
    rpg->menu->status = ON_GAME;
}

void load_save(rpg_t *rpg)
{
    FILE *fd = fopen("save/save.txt", "r");
    char *map;

    if (fd == NULL) {
        rpg->menu->status = ON_NEW_GM;
        return;
    }
    map = my_open(fd);
    reload_new_game(rpg);
    load_values(map, rpg);
    sfSound_stop(rpg->menu->main_menu->menu_snd->a_menu);
    set_loaded_value(rpg);
    free(map);
    fclose(fd);
}