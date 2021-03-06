/*
** EPITECH PROJECT, 2021
** pause button by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** pause_button.c
*/

#include "../../../../include/defender.h"

void pause_but(pause_t *pause)
{
    pause->pause_tex = sfTexture_createFromFile
    ("Ressources/button/menu/setting/settings.png", NULL);
    pause->pause_spt = sfSprite_create();
    sfVector2f scale = {0.5, 0.5};
    sfVector2f pause_pos = {1690, 10};

    sfSprite_setTexture(pause->pause_spt, pause->pause_tex, sfFalse);
    sfSprite_setPosition(pause->pause_spt, pause_pos);
    sfSprite_setScale(pause->pause_spt, scale);
}

void draw_pause(pause_t *pause, window_t *wnd, core_t *core)
{
    sfRenderWindow_drawSprite(wnd->window, core->menu->set_bg_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, core->menu->name_spt, NULL);
    sfRenderWindow_drawSprite(wnd->window, core->menu->stg->vol->vol_spt, NULL);
    sfSprite_setTextureRect(core->menu->stg->vol->vol_nbr_spt,
                            core->menu->stg->vol->vol_nbr);
    sfRenderWindow_drawSprite
    (wnd->window, core->menu->stg->vol->vol_nbr_spt, NULL);
    print_fullscr(core->menu->stg, wnd, core->menu);
    print_medscr(core->menu->stg, wnd, core->menu);
    print_up_vol(core->menu, wnd);
    print_down_vol(core->menu, wnd);
    draw_restart(pause, core->menu, wnd);
    sfRenderWindow_drawSprite(wnd->window, pause->pause_spt, NULL);
    draw_leave_pause(pause, core->menu, wnd);
}

void pause_on(menu_t *menu)
{
    if (menu->button->enable_click == TRUE) {
        menu->pause_on = TRUE;
        menu->go_to_stg = TRUE;
    }
}

void pause_click(pause_t *pause, window_t *wnd, core_t *core)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);
    sfFloatRect pause_pos = sfSprite_getGlobalBounds(pause->pause_spt);

    if ((mouse_pos.x >= box_size_x(wnd, pause_pos.left) && mouse_pos.x <=
        (box_size_x(wnd, pause_pos.left) + box_size_x(wnd, pause_pos.width)))
        && (mouse_pos.y >= box_size_y(wnd, pause_pos.top) && mouse_pos.y <=
        (box_size_y(wnd, pause_pos.top) + box_size_y(wnd, pause_pos.height)))) {
        pause_on(core->menu);
    } else
        sfRenderWindow_drawSprite(wnd->window,
                                pause->pause_spt, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue) {
        core->menu->pause_on = TRUE;
        core->menu->go_to_stg = TRUE;
    }
}
