/*
** EPITECH PROJECT, 2020
** csfml
** File description:
** windo_disp
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>

int sprite(sfRenderWindow *window)
{
    sfTexture *background = sfTexture_createFromFile("all_sprites/map/map_og.png", NULL);
    sfSprite *my_background = sfSprite_create();

    sfSprite_setTexture(my_background, background, sfFalse);
    sfRenderWindow_drawSprite(window, my_background, NULL);
    sfSprite_destroy(my_background);
    sfTexture_destroy(background);
    return (0);
}

int keep_window_open(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {254, 236, 64};
    sfEvent event;

    window = sfRenderWindow_create(video_mode, "MyWindow", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_clear(window, sfBlack);
        sprite(window);
        sfRenderWindow_display(window);
    }
    sfRenderWindow_destroy(window);
    return (0);
}

int main(void)
{
    int height;
    int width;

    sfRenderWindow *window;
    width = 500;
    height = 500;
    keep_window_open();
}