/*
** EPITECH PROJECT, 2021
** init_phone
** File description:
** init_phone
*/

#include "../../../include/func_name.h"

static void init_begin_notifs(rpg_t *rpg)
{
    sfTexture *text;

    text = sfTexture_createFromFile("assets/phone/sergent_martinez.png", NULL);
    rpg->game->in_game->phone->phone[0] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->phone->phone[0], text, sfTrue);
    text = sfTexture_createFromFile("assets/phone/notif1.png", NULL);
    rpg->game->in_game->phone->phone[1] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->phone->phone[1], text, sfTrue);
    text = sfTexture_createFromFile("assets/phone/notif2.png", NULL);
    rpg->game->in_game->phone->phone[2] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->phone->phone[2], text, sfTrue);
    text = sfTexture_createFromFile("assets/phone/incoming_call.png", NULL);
    rpg->game->in_game->phone->phone[3] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->phone->phone[3], text, sfTrue);
    text = sfTexture_createFromFile("assets/phone/call.png", NULL);
    rpg->game->in_game->phone->phone[4] = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->phone->phone[4], text, sfTrue);
}

static void init_phone_notifs(rpg_t *rpg)
{
    sfTexture *text;
    sfVector2f phone_pos = {1424.5, 50.5};
    char *paths = "assets/phone/notif";
    char *nb = malloc(sizeof(char) * 2);

    rpg->game->in_game->phone->phone = malloc(sizeof(sfSprite *) * 11);
    nb[0] = '3';
    nb[1] = '\0';
    init_begin_notifs(rpg);
    for (int i = NOTIF3; i < NO_NOTIF; i++) {
        rpg->game->in_game->phone->phone[i] = sfSprite_create();
        text = sfTexture_createFromFile
        (my_strcat(paths, my_strcat(nb, ".png")), NULL);
        sfSprite_setTexture(rpg->game->in_game->phone->phone[i], text, sfTrue);
        nb[0]++;
    }
    for (int i = NOTIF_MARTINEZ; i < NO_NOTIF; i++)
        sfSprite_setPosition(rpg->game->in_game->phone->phone[i], phone_pos);
}

void init_phone(rpg_t *rpg)
{
    sfTexture *icone =
    sfTexture_createFromFile("assets/phone/phone_icon.png", NULL);
    sfTexture *notif =
    sfTexture_createFromFile("assets/phone/phone_notif.png", NULL);

    rpg->game->in_game->phone->phone_icone = sfSprite_create();
    rpg->game->in_game->phone->phone_notif = sfSprite_create();
    sfSprite_setTexture(rpg->game->in_game->phone->phone_icone, icone, sfTrue);
    sfSprite_setTexture(rpg->game->in_game->phone->phone_notif, notif, sfTrue);
    sfSprite_setPosition(rpg->game->in_game->phone->phone_icone,
    put_in_vector2f(1800, 869));
    sfSprite_setPosition(rpg->game->in_game->phone->phone_notif,
    put_in_vector2f(1832, 838));
    init_phone_notifs(rpg);
}