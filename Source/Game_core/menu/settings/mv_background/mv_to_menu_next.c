/*
** EPITECH PROJECT, 2021
** move to settings by Timothy CONIEL
** File description:
** switch between settings & menu
*/

#include "../../../../../include/defender.h"

void mv_menu_one(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->up_click_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->up_click_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->up_click_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->down_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->down_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->down_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->hover_down_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->hover_down_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->hover_down_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->down_click_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->down_click_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->down_click_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->vol_nbr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->vol_nbr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->vol_nbr_spt, pos);
}

void mv_menu_two(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->stg->hover_return_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->hover_return_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->hover_return_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->click_return_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->click_return_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->click_return_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->vol_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->vol_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->vol_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->up_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->up_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->up_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->vol->hover_up_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->vol->hover_up_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->vol->hover_up_spt, pos);
}

void mv_menu_three(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->stg->click_fullscr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->click_fullscr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->click_fullscr_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->medscr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->medscr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->medscr_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->hover_medscr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->hover_medscr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->hover_medscr_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->click_medscr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->click_medscr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->click_medscr_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->return_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->return_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->return_spt, pos);
}

void mv_menu_four(menu_t *menu, sfVector2f pos)
{
    pos.x = sfSprite_getGlobalBounds(menu->button->setting_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->setting_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->setting_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->hover_setting_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->hover_setting_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->hover_setting_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->button->click_setting_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->button->click_setting_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->button->click_setting_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->fullscr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->fullscr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->fullscr_spt, pos);
    pos.x = sfSprite_getGlobalBounds(menu->stg->hover_fullscr_spt).left;
    pos.y = sfSprite_getGlobalBounds(menu->stg->hover_fullscr_spt).top;
    pos.x += 20;
    sfSprite_setPosition(menu->stg->hover_fullscr_spt, pos);
}
