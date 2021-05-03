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

void reload_new_game(rpg_t *rpg)
{
    sfVector2f *pos_characters = malloc(sizeof(sfVector2f) * 5);

    pos_characters[MAXOU] = put_in_vector2f((float)396, (float)362);
    pos_characters[TIMO] = put_in_vector2f((float)689, (float)362);
    pos_characters[LUDO] = put_in_vector2f((float)982, (float)362);
    pos_characters[SYLVIE] = put_in_vector2f((float)1275, (float)362);
    for (int i = MAXOU; i < NO_CHARACTERS; i++) {
        sfSprite_setPosition(rpg->menu->main_menu->new_game->select[i],
        pos_characters[i]);
    }
    rpg->game->in_game->map->status = MAP_INSIDE_POLICE;
    rpg->game->in_game->map->pos_map[MAP_INSIDE_POLICE] =
    put_in_vector2f(-1265, -959);
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