/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** audios
*/

#include "../../../include/rpg.h"

void create_boom(rpg_t *rpg)
{
    rpg->main_menu->create_start =
    sfSoundBuffer_createFromFile("assets/audios/start.ogg");
    rpg->main_menu->start = sfSound_create();
    sfSound_setBuffer(rpg->main_menu->start, rpg->main_menu->create_start);
    rpg->main_menu->create_a_menu =
    sfSoundBuffer_createFromFile("assets/audios/menu.ogg");
    rpg->main_menu->a_menu = sfSound_create();
    sfSound_setBuffer(rpg->main_menu->a_menu, rpg->main_menu->create_a_menu);
    sfSound_setLoop(rpg->main_menu->a_menu, sfTrue);
}