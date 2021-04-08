/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** options_graph
*/

#include "../../include/rpg.h"

void clic_menu(rpg_t *rpg)
{
    if (rpg->basics->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 361.5)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 460)))
            rpg->main_menu->opt_status = 0;
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 460.5)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 559.5)))
            rpg->main_menu->opt_status = 1;
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 255)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 559.5)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 789)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 658.5)))
            rpg->main_menu->opt_status = 2;
    }
}

void select_resolution(rpg_t *rpg)
{
    if (rpg->basics->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 1589.804)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 613.25)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 1614.304)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 637.75)))
            rpg->basics->resolution = 0;
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 1589.804)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 583.75)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 1614.304)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 597.25)))
            rpg->basics->resolution = 1;
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 1589.804)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 530.25)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 1614.304)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 554.75)))
            rpg->basics->resolution = 2;
    }
}

void select_fps(rpg_t *rpg)
{
    if (rpg->basics->event.type == sfEvtMouseButtonPressed) {
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 1477.554)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 382.25)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 1502.054)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 406.75)))
            rpg->basics->fps = 30;
        if (((rpg->basics->mouse.x) >= adapt_x(rpg, 1631.554)) &&
        ((rpg->basics->mouse.y) >= adapt_y(rpg, 382.25)) &&
        (rpg->basics->mouse.x <= adapt_x(rpg, 1656.054)) &&
        (rpg->basics->mouse.y <= adapt_y(rpg, 406.75)))
            rpg->basics->fps = 60;
    }
}

void draw_square(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->graphismes[RES19x80], NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->graphismes[RES12x20], NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->graphismes[RES11x30], NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->graphismes[FPS60], NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window,
    rpg->main_menu->graphismes[FPS30], NULL);
}

int manage_window_size(rpg_t *rpg)
{
    sfVector2u size1 = {1920, 1080};

    sfSprite_setTexture(rpg->main_menu->graphismes[RES19x80],
    rpg->main_menu->empty_square, sfTrue);
    sfSprite_setTexture(rpg->main_menu->graphismes[RES12x20],
    rpg->main_menu->empty_square, sfTrue);
    sfSprite_setTexture(rpg->main_menu->graphismes[RES11x30],
    rpg->main_menu->empty_square, sfTrue);
    if (rpg->basics->resolution == 0) {
        sfSprite_setTexture(rpg->main_menu->graphismes[RES19x80],
        rpg->main_menu->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basics->my_window, size1);
    }
    manage_fill_resolution(rpg);
}