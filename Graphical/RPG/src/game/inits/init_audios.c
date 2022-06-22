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
    sfSound_setBuffer(rpg->tutorial->tuto, rpg->tutorial->amb_tuto);
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

void init_phone_sound(rpg_t *rpg)
{
    rpg->game->in_game->phone->phone_buffer =
    sfSoundBuffer_createFromFile("assets/audios/sms.ogg");
    rpg->game->in_game->phone->notif_sound = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->phone->notif_sound,
    rpg->game->in_game->phone->phone_buffer);
    sfSound_setVolume(rpg->game->in_game->phone->notif_sound, 50);
    rpg->game->in_game->phone->phone_buffer = sfSoundBuffer_createFromFile
    ("assets/audios/incoming_call.ogg");
    rpg->game->in_game->phone->call_sound = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->phone->call_sound,
    rpg->game->in_game->phone->phone_buffer);
    sfSound_setLoop(rpg->game->in_game->phone->call_sound, sfTrue);
    sfSound_setVolume(rpg->game->in_game->phone->call_sound, 50);
}

void init_pitch_riley(rpg_t *rpg)
{
    rpg->game->in_game->ig_sound->riley_buffer =
    sfSoundBuffer_createFromFile("assets/audios/riley.ogg");
    rpg->game->in_game->ig_sound->riley = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->ig_sound->riley,
    rpg->game->in_game->ig_sound->riley_buffer);
    sfSound_setVolume(rpg->game->in_game->ig_sound->riley, 50);
    rpg->game->in_game->ig_sound->riley_buffer = sfSoundBuffer_createFromFile
    ("assets/audios/call_riley_warren.ogg");
    rpg->game->in_game->ig_sound->riley_call = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->ig_sound->riley_call,
    rpg->game->in_game->ig_sound->riley_buffer);
    sfSound_setVolume(rpg->game->in_game->ig_sound->riley_call, 50);
    rpg->game->in_game->ig_sound->riley_buffer = sfSoundBuffer_createFromFile
    ("assets/audios/riley_warren.ogg");
    rpg->game->in_game->ig_sound->riley_warren = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->ig_sound->riley_warren,
    rpg->game->in_game->ig_sound->riley_buffer);
    sfSound_setVolume(rpg->game->in_game->ig_sound->riley_warren, 50);
}

void init_alerts(rpg_t *rpg)
{
    rpg->game->in_game->phone->phone_buffer = sfSoundBuffer_createFromFile
    ("assets/audios/alarme.ogg");
    rpg->game->in_game->phone->alarm = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->phone->alarm,
    rpg->game->in_game->phone->phone_buffer);
    sfSound_setVolume(rpg->game->in_game->phone->alarm, 50);
    rpg->game->in_game->objects->car->car_buffer = sfSoundBuffer_createFromFile
    ("assets/audios/sirene.ogg");
    rpg->game->in_game->objects->car->sirene = sfSound_create();
    sfSound_setBuffer(rpg->game->in_game->objects->car->sirene,
    rpg->game->in_game->objects->car->car_buffer);
    sfSound_setVolume(rpg->game->in_game->objects->car->sirene, 50);
}