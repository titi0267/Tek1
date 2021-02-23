/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** initialize_wnd
*/

#include "../../include/defender.h"
#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <fcntl.h>

void initialize_wnd(window_t *wnd)
{
    wnd->scr_size.width = 1920;
    wnd->scr_size.height = 1080;
    wnd->scr_size.bitsPerPixel = 32;
    wnd->window = sfRenderWindow_create(wnd->scr_size, "My_defender",
                                        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd->window, 55);
}

void poll_event(window_t *wnd)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(wnd->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(wnd->window);
    }
}

void mia(window_t *wnd)
{
    sfTexture *mia = sfTexture_createFromFile("Ressources/481_1000.jpg", NULL);
    sfSprite *sandwich = sfSprite_create();
    sfVector2f scale = {1.3f, 1.3f};

    sfSprite_setTexture(sandwich, mia, sfFalse);
    sfSprite_setScale(sandwich, scale);
    sfRenderWindow_drawSprite(wnd->window, sandwich, NULL);
}

void mia2(window_t *wnd)
{
    sfTexture *mia = sfTexture_createFromFile("Ressources/690_160.jpg", NULL);
    sfSprite *sandwich = sfSprite_create();
    sfVector2f scale = {1.3f, 1.3f};
    sfVector2f pos = {1080, 200};

    sfSprite_setTexture(sandwich, mia, sfFalse);
    sfSprite_setPosition(sandwich, pos);
    sfSprite_setScale(sandwich, scale);
    sfRenderWindow_drawSprite(wnd->window, sandwich, NULL);
}

void wnd_open(core_t *core)
{
    initialize_wnd(core->wnd);
    while (sfRenderWindow_isOpen(core->wnd->window)) {
        mia(core->wnd);
        mia2(core->wnd);
        poll_event(core->wnd);
        sfRenderWindow_display(core->wnd->window);
    }
    destroy1(core);
}