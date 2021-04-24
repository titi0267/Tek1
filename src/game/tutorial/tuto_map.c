/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tuto_map
*/

#include "../../../include/func_name.h"

void tuto_map(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->tutorial->map_tuto, NULL);
}