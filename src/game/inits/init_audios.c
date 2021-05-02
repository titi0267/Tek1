/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_audios
*/

#include "../../../include/func_name.h"

void init_amb_tuto_game(rpg_t *rpg)
{
    rpg->tutorial->amb_tuto =
    sfSoundBuffer_createFromFile("assets/audios/music/tuto.ogg");
    rpg->tutorial->tuto = sfSound_create();
    sfSound_setBuffer(rpg->tutorial->tuto,
    rpg->tutorial->amb_tuto);
    sfSound_setVolume(rpg->tutorial->tuto, 50);
    sfSound_setLoop(rpg->tutorial->tuto, sfTrue);
    rpg->game->in_game->ig_sound->amb_game =
    sfSoundBuffer_createFromFile("assets/audios/music/amb_game.ogg");
    rpg->game->in_game->ig_sound->game = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->ig_sound->game,
    rpg->game->in_game->ig_sound->amb_game);
    sfSound_setVolume(rpg->game->in_game->ig_sound->game, 50);
    sfSound_setLoop(rpg->game->in_game->ig_sound->game, sfTrue);
}