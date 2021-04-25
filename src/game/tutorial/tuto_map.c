/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto_map
*/

#include "../../../include/func_name.h"

void print_player_move(rpg_t *rpg)
{
    sfVector2f pos = {660, 540};

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
        rpg->menu->main_menu->new_game->character_chosen] > 3) {
        rpg->menu->main_menu->new_game->offset_character[
        rpg->menu->main_menu->new_game->character_chosen] = 0;
    }
    nbr += rpg->basic->cnf->clk->time_loop;
    sfSprite_setTextureRect(rpg->game->in_game->objects->players
    [rpg->menu->main_menu->new_game->character_chosen],
    rpg->menu->main_menu->new_game->char_in_game[direction]);
}

void move_up_down_tuto_map(rpg_t *rpg)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[UP]->text[0]) {
        rpg->tutorial->map_pos.y += 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, UP);
    }
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[DOWN]->text[0]) {
        rpg->tutorial->map_pos.y -= 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, DOWN);
    }
}

void move_side_tuto_map(rpg_t *rpg)
{
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[LEFT]->text[0]) {
        rpg->tutorial->map_pos.x += 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, LEFT);
    }
    if (rpg->basic->evt->event.text.unicode ==
    (unsigned int)rpg->menu->stg->key_bnd->control[RIGHT]->text[0]) {
        rpg->tutorial->map_pos.x -= 3;
        sfSprite_setPosition(rpg->tutorial->map_tuto, rpg->tutorial->map_pos);
        rect_move_player(rpg, RIGHT);
    }
    move_up_down_tuto_map(rpg);
}

void tuto_map(rpg_t *rpg)
{
    move_side_tuto_map(rpg);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->tutorial->map_tuto, NULL);
    print_player_move(rpg);
}
