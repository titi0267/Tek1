/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** options
*/

#include "../../include/rpg.h"

void clic_options(rpg_t *rpg)
{
    if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basics->mouse.y) >= adapt_y(rpg, 361.5)) &&
    (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basics->mouse.y <= adapt_y(rpg, 460)))
        sfRenderWindow_drawSprite(rpg->basics->my_window,
        rpg->main_menu->options[GRAPH], NULL);
    if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basics->mouse.y) >= adapt_y(rpg, 460.5)) &&
    (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basics->mouse.y <= adapt_y(rpg, 559.5)))
        sfRenderWindow_drawSprite(rpg->basics->my_window,
        rpg->main_menu->options[SOUND], NULL);
    if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basics->mouse.y) >= adapt_y(rpg, 559.5)) &&
    (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basics->mouse.y <= adapt_y(rpg, 658.5)))
        sfRenderWindow_drawSprite(rpg->basics->my_window,
        rpg->main_menu->options[GAME_OPTIONS], NULL);
}

void clic_options1(rpg_t *rpg)
{
    if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
    ((rpg->basics->mouse.y) >= adapt_y(rpg, 684.5)) &&
    (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
    (rpg->basics->mouse.y <= adapt_y(rpg, 783.5)))
        sfRenderWindow_drawSprite(rpg->basics->my_window,
        rpg->main_menu->options[MAIN_MENU], NULL);
    if (rpg->basics->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 684.5)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 783.5)))
            rpg->status = 1;
    }
}

void show_menus(rpg_t *rpg)
{
    if (rpg->main_menu->opt_status == 0) {
        sfRenderWindow_drawSprite(rpg->basics->my_window
        ,rpg->main_menu->options[GRAPH_F], NULL);
        sfRenderWindow_drawSprite(rpg->basics->my_window
        ,rpg->main_menu->options[GRAPH], NULL);
        draw_square(rpg);
        select_fps(rpg);
        select_resolution(rpg);
        manage_window_size(rpg);
    }
    if (rpg->main_menu->opt_status == 1) {
        sfRenderWindow_drawSprite(rpg->basics->my_window
        ,rpg->main_menu->options[SOUND_F], NULL);
        sfRenderWindow_drawSprite(rpg->basics->my_window
        ,rpg->main_menu->options[SOUND], NULL);
        show_music_sound(rpg);
        manage_sound(rpg);
    }
}

void show_menus2(rpg_t *rpg)
{
    if (rpg->main_menu->opt_status == 2) {
        sfRenderWindow_drawSprite(rpg->basics->my_window
        ,rpg->main_menu->options[GAME_OPTIONS_F], NULL);
        sfRenderWindow_drawSprite(rpg->basics->my_window
        ,rpg->main_menu->options[GAME_OPTIONS], NULL);
    }
}

void options(rpg_t *rpg)
{
    show_menus(rpg);
    show_menus2(rpg);
    clic_menu(rpg);
    clic_options(rpg);
    clic_options1(rpg);
    sfRenderWindow_drawSprite(rpg->basics->my_window
    ,rpg->main_menu->options[NO], NULL);
}