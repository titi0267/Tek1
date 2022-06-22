/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** exit_action
*/

#include "../../../include/func_name.h"

void click_on_resume(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
    (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 390)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 465)))) {
        rpg->menu->status = ON_GAME;
    }
}

void click_on_option(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
    (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 500)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 577)))) {
        rpg->menu->status = ON_OPTION_PAUSE;
    }
}

void reload_new_game2(rpg_t *rpg)
{
    rpg->tutorial->tutorial_stat = TUTO1;
    rpg->tutorial->status_sound_tuto = FALSE;
    rpg->game->in_game->game_status = -1;
    rpg->game->in_game->phone->phone_status = 1;
    rpg->game->in_game->phone->notif_bool = FALSE;
    rpg->game->start->status_cinematic1 = FALSE;
    rpg->game->in_game->phone->notif_index = 0;
    rpg->game->in_game->phone->notif_prev = 0;
    init_stats_basic_value(rpg);
    rpg->game->in_game->map->last_pos = -1;
    rpg->game->in_game->objects->speed_status = WALK_SPEED;
    rpg->game->in_game->ig_sound->status_sound_game = FALSE;
    rpg->game->in_game->phone->call_status = FALSE;
    rpg->game->in_game->map->last_pos = DOWN;
    rpg->game->in_game->stats->xp_max_value = 100;
    rpg->game->in_game->stats->xp_value = 0;
    rpg->game->in_game->objects->car->status = 1;
    rpg->game->in_game->map->car_map = MAP_OUTSIDE_POLICE;
    reset_inventory(rpg);
    init_positions(rpg);
    rpg->game->in_game->objects->car->status = -1;
}

void reload_new_game(rpg_t *rpg)
{
    sfVector2f *pos_characters = malloc(sizeof(sfVector2f) * 5);

    pos_characters[MAXOU] = put_in_vector2f((float)396, (float)362);
    pos_characters[TIMO] = put_in_vector2f((float)689, (float)362);
    pos_characters[LUDO] = put_in_vector2f((float)982, (float)362);
    pos_characters[SYLVIE] = put_in_vector2f((float)1275, (float)362);
    for (int i = MAXOU; i < NO_CHARACTERS; i++)
        sfSprite_setPosition(rpg->menu->main_menu->new_game->characters[i],
        pos_characters[i]);
    rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE] =
    put_in_vector2f(-1265, -959);
    sfSprite_setPosition(rpg->game->in_game->map->maps
    [rpg->game->in_game->map->status],
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE]);
    rpg->menu->main_menu->menu_snd->status_sound_menu = FALSE;
        rpg->game->in_game->phone->alarm_status = FALSE;
    rpg->menu->stg->stg_scene = GRAPH_SCN;
    rpg->game->in_game->inventory->shortcut_it = INVENTORY_OFF;
    set_pos_car(rpg);
    reload_new_game2(rpg);
}

void click_on_quit(rpg_t *rpg)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == TRUE &&
    (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 761)) &&
    ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, 614)) &&
    (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1170)) &&
    (rpg->basic->cnf->mouse.y <= adapt_y(rpg, 689)))) {
        save_map(rpg);
        reload_new_game(rpg);
        rpg->menu->status = ON_MENU;
    }
}