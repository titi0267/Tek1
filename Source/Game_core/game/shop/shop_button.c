/*
** EPITECH PROJECT, 2021
** shop button by Timothy CONIEL & Tristan HOURTOULLE
** File description:
** shop button
*/

#include "../../../../include/defender.h"

void shop_button(shop_t *shop)
{
    shop->shop_tex = sfTexture_createFromFile(
                            "Ressources/button/settings/size/hover_1920-1080.png",
                            NULL);
    shop->shop_spt = sfSprite_create();
    sfVector2f scale = {0.25f, 0.25f};
    sfVector2f hover_medscr_pos = {3320, 600};

    sfSprite_setTexture(shop->shop_spt, shop->shop_tex, sfFalse);
    sfSprite_setPosition(shop->shop_spt, hover_medscr_pos);
    sfSprite_setScale(shop->shop_spt, scale);
}

