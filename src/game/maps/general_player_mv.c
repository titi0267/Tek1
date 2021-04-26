/*
** EPITECH PROJECT, 2021
** general functions to move
** File description:
** player_moves.c
*/

#include "../../../include/func_name.h"

void stopped_moving(rpg_t *rpg)
{
    if ((rpg->basic->evt->event.text.unicode !=
    (unsigned int)rpg->menu->stg->key_bnd->control[UP]->text[0]) &&
    (rpg->basic->evt->event.text.unicode !=
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0]) &&
    (rpg->basic->evt->event.text.unicode !=
    (unsigned int)rpg->menu->stg->key_bnd->control[LEFT]->text[0]) &&
    (rpg->basic->evt->event.text.unicode !=
    (unsigned int)rpg->menu->stg->key_bnd->control[RIGHT]->text[0]))
        display_character_at_stop(rpg,
        rpg->menu->main_menu->new_game->character_chosen, 1);
}

void print_player_move(rpg_t *rpg)
{
    sfVector2f pos = {960, 540};

    stopped_moving(rpg);
    sfSprite_setPosition(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen], pos);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen], NULL);
}

void rect_move_player(rpg_t *rpg, int direction)
{
    static float nbr = 0;

    if (nbr > 0.1) {
        rpg->menu->main_menu->new_game->char_in_game[direction].left =
        (rpg->menu->main_menu->new_game->offset_character
        [rpg->menu->main_menu->new_game->character_chosen] *
        (rpg->menu->main_menu->new_game->char_in_game[direction].width + 196)) +
        100;
        nbr = 0;
        rpg->menu->main_menu->new_game->offset_character
        [rpg->menu->main_menu->new_game->character_chosen]++;
    }
    if (rpg->menu->main_menu->new_game->offset_character[
        rpg->menu->main_menu->new_game->character_chosen] > 3)
        rpg->menu->main_menu->new_game->offset_character[
        rpg->menu->main_menu->new_game->character_chosen] = 0;
    nbr += rpg->basic->cnf->clk->time_loop;
    sfSprite_setTextureRect(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[direction]);
}

void move_up_down_map(rpg_t *rpg,int on_map)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[UP]->text[0]) {
        rpg->game->in_game->map->pos_map[on_map].y += 3;
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        //sfSprite_setPosition(rpg->game->in_game->map->collisions[on_map],
        //rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, UP);
        rpg->game->in_game->map->last_pos = UP;
    }
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0]) {
        rpg->game->in_game->map->pos_map[on_map].y -= 3;
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        //sfSprite_setPosition(rpg->game->in_game->map->collisions[on_map],
        //rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, DOWN);
        rpg->game->in_game->map->last_pos = DOWN;
    }
}

void move_side_map(rpg_t *rpg, int on_map)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[LEFT]->text[0]) {
        rpg->game->in_game->map->pos_map[on_map].x += 3;
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        //sfSprite_setPosition(rpg->game->in_game->map->collisions[on_map],
        //rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, LEFT);
        rpg->game->in_game->map->last_pos = LEFT;
    }
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[RIGHT]->text[0]) {
        rpg->game->in_game->map->pos_map[on_map].x -= 3;
        sfSprite_setPosition(rpg->game->in_game->map->maps[on_map],
        rpg->game->in_game->map->pos_map[on_map]);
        //sfSprite_setPosition(rpg->game->in_game->map->collisions[on_map],
        //rpg->game->in_game->map->pos_map[on_map]);
        rect_move_player(rpg, RIGHT);
        rpg->game->in_game->map->last_pos = RIGHT;
    }
    move_up_down_map(rpg, on_map);
}