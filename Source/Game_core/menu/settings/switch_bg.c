/*
** EPITECH PROJECT, 2021
** switch background by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** switch_bg.c
*/

#include "../../../../include/defender.h"
#include <stdio.h>

void click_settings(menu_t *menu, sfEvent event, window_t *wnd)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(wnd->window);

    if (event.type == sfEvtMouseButtonPressed) {
        if ((mouse_pos.x >= box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).left) &&
            mouse_pos.x <= (box_size_x(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).left) +
            box_size_x(wnd,
                sfSprite_getGlobalBounds(menu->button->setting_spt).width))) &&
            (mouse_pos.y >= box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).top) &&
            mouse_pos.y <= (box_size_y(wnd,
                    sfSprite_getGlobalBounds(menu->button->setting_spt).top) +
            box_size_y(wnd,
                sfSprite_getGlobalBounds(menu->button->setting_spt).height))))
                menu->settings = TRUE;
    }
}

/*void create_list_switch(menu_t **menu, int spt)
{
    struct menu_s *element = malloc(sizeof(*element));
    //(*menu)->mv_spt = malloc(sizeof(sfSprite *));

    if(!element)
        exit(ERROR);
    element->mv_spt = sfSprite_copy((*menu)->list[spt]);
    element->next = *menu;
    *menu = element;
    //element->next = NULL;
    my_printf("spt = %i\n", spt);
}

void fill_list(menu_t **menu, window_t *wnd)
{
    create_sprite(*menu);

    for (int i = 0; (*menu)->list[i] != NULL; i++) {
        my_printf("i = %i\n", i);
        //ssfRenderWindow_drawSprite(wnd->window, (*menu)->list[i], NULL);
        create_list_switch(menu, i);
    }
}

void mv_spt_list(menu_t **menu)
{
    sfVector2f global_pos;
    struct menu_s *element = (*menu);

    while(element != NULL)
    {
        global_pos.x = sfSprite_getGlobalBounds(element->mv_spt).left;
        global_pos.y = sfSprite_getGlobalBounds(element->mv_spt).top;
        global_pos.x -= 20;
        sfSprite_setPosition(element->mv_spt, global_pos);
        element = element->next;
    }
}*/

void mv_spt_list(menu_t *menu, window_t *wnd)
{
    sfVector2f global_pos;

    create_sprite_arr(menu);
    for  (int i = 0; menu->list[i] != NULL; i++) {
        global_pos.x = sfSprite_getGlobalBounds(menu->list[i]).left;
        global_pos.y = sfSprite_getGlobalBounds(menu->list[i]).top;
        global_pos.x -= 20;
        sfSprite_setPosition(menu->list[i], global_pos);
        sfRenderWindow_drawSprite(wnd->window, menu->list[i], NULL);
    }
    return_to_one(menu);
}

void mv_spt_return(menu_t *menu, window_t *wnd)
{
    sfVector2f global_pos;

    create_sprite_arr(menu);
    for  (int i = 0; menu->list[i] != NULL; i++) {
        global_pos.x = sfSprite_getGlobalBounds(menu->list[i]).left;
        global_pos.y = sfSprite_getGlobalBounds(menu->list[i]).top;
        global_pos.x += 20;
        sfSprite_setPosition(menu->list[i], global_pos);
        sfRenderWindow_drawSprite(wnd->window, menu->list[i], NULL);
    }
    return_to_one(menu);
}

void switch_bg(menu_t *menu, window_t *wnd)
{
    sfVector2f pos;

    if (sfSprite_getGlobalBounds(menu->set_bg_spt).left > 0 &&
        menu->return_to_menu == FALSE) {
        mv_spt_list(menu, wnd);
    } else if (sfSprite_getGlobalBounds(menu->bgd_spt).left < 0 &&
            menu->return_to_menu == TRUE) {
        mv_spt_return(menu, wnd);
    }
    if (sfSprite_getGlobalBounds(menu->bgd_spt).left >= 0) {
        menu->settings = FALSE;
        menu->return_to_menu = FALSE;
    }
}

void draw_spt_setting(menu_t *menu, window_t *wnd)
{
    switch_bg(menu, wnd);
    settings_spt(menu, wnd);
    hover_return(menu->stg, wnd);
    hover_leave(menu->button, wnd);
    hover_fullscr(menu->stg, wnd);
    hover_medscr(menu->stg, wnd);
}
