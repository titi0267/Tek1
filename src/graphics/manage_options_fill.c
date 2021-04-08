/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** manage_options_fill
*/

#include "../../include/rpg.h"

void manage_fill_fps(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->main_menu->graphismes[FPS30],
    rpg->main_menu->empty_square, sfTrue);
    sfSprite_setTexture(rpg->main_menu->graphismes[FPS60],
    rpg->main_menu->empty_square, sfTrue);
    if (rpg->basics->fps == 30) {
        sfSprite_setTexture(rpg->main_menu->graphismes[FPS30],
        rpg->main_menu->fill_square, sfTrue);
    }
    if (rpg->basics->fps == 60) {
        sfSprite_setTexture(rpg->main_menu->graphismes[FPS60],
        rpg->main_menu->fill_square, sfTrue);
    }
}

void manage_fill_resolution(rpg_t *rpg)
{
    sfVector2u size2 = {1280, 720};
    sfVector2u size3 = {1160, 630};

    if (rpg->basics->resolution == 1) {
        sfSprite_setTexture(rpg->main_menu->graphismes[RES12x20],
        rpg->main_menu->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basics->my_window, size2);
    }
    if (rpg->basics->resolution == 2) {
        sfSprite_setTexture(rpg->main_menu->graphismes[RES11x30],
        rpg->main_menu->fill_square, sfTrue);
        sfRenderWindow_setSize(rpg->basics->my_window, size3);
    }
    manage_fill_fps(rpg);
}

void show_music_sound(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->basics->my_window
    ,rpg->main_menu->graphismes[CIRCLE_MUSIC], NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window
    ,rpg->main_menu->graphismes[CIRCLE_DIAG], NULL);
    sfRenderWindow_drawSprite(rpg->basics->my_window
    ,rpg->main_menu->graphismes[CIRCLE_AMBT], NULL);
}

void manage_sound(rpg_t *rpg)
{
    sfFloatRect music = sfSprite_getGlobalBounds
    (rpg->main_menu->graphismes[CIRCLE_MUSIC]);
    sfVector2f sp_center = {music.width / 2, music.height / 2};
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basics->my_window,
    sfMouse_getPositionRenderWindow(rpg->basics->my_window), NULL);
    sfBool hover = sfFloatRect_contains(
    &rpg->main_menu->graphismes[CIRCLE_MUSIC], mouse.x, mouse.y);

    sfSprite_setOrigin(rpg->main_menu->graphismes[CIRCLE_MUSIC], sp_center);
    mouse.y = 363;
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        // if (((rpg->basics->mouse.x) >= adapt_x(rpg, music.left)) &&
        // ((rpg->basics->mouse.y) >= adapt_y(rpg, music.top)) &&
        // (rpg->basics->mouse.x <= adapt_x(rpg, music.left + music.width)) &&
        // (rpg->basics->mouse.y <= adapt_y(rpg, music.top + music.height)) &&
        // (rpg->basics->mouse.x <= adapt_x(rpg, 1678.51) &&
        // (rpg->basics->mouse.x) >= adapt_x(rpg, 1452.608)))
        if (hover == sfTrue)
            sfSprite_setPosition(rpg->main_menu->graphismes[CIRCLE_MUSIC],
            mouse);
    }
}