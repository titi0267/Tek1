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
    sfVector2i wnd_pos = {0, 0};

    wnd->scr_size.width = 1920;
    wnd->scr_size.height = 1080;
    wnd->scr_size.bitsPerPixel = 32;
    wnd->window = sfRenderWindow_create(wnd->scr_size, "My_defender",
                                        sfClose, NULL);
    sfRenderWindow_setFramerateLimit(wnd->window, 55);
    sfRenderWindow_setPosition(wnd->window, wnd_pos);
}
