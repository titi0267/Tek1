/*
** EPITECH PROJECT, 2021
** backgorund by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** background.c
*/

#include "../../../include/defender.h"

void game_bgd(game_t *game)
{
    game->game_bgd_tex = sfTexture_createFromFile(
                        "Ressources/background/game_bgd.png",
                        NULL);
    game->game_bgd_spt = sfSprite_create();
    sfVector2f scale = {1.4, 1.27};
    sfVector2f setting_pos = {0, 0};

    sfSprite_setTexture(game->game_bgd_spt,
                        game->game_bgd_tex, sfFalse);
    sfSprite_setPosition(game->game_bgd_spt, setting_pos);
    sfSprite_setScale(game->game_bgd_spt, scale);
}
