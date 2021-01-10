/*
** EPITECH PROJECT, 2021
** Start by Timothy CONIEL
** File description:
** start.c
*/
#include "../include/my.h"

void start_text(menu_t *menu)
{
    menu->press = sfText_create();
    menu->count = sfText_create();
    menu->font = sfFont_createFromFile("ressource/score.ttf");
    init_text(menu);
    sfText_setFont(menu->press, menu->font);
    sfText_setFont(menu->count, menu->font);
    sfText_setCharacterSize(menu->press, menu->font_size);
    sfText_setCharacterSize(menu->count, 150);
    sfText_setColor(menu->press, sfBlack);
    sfText_setColor(menu->count, sfBlack);
    sfText_setPosition(menu->press, menu->text_pos);
    sfText_setPosition(menu->count, menu->count_pos);
}
