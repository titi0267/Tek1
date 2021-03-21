/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** destroy_one
*/

#include "../../include/defender.h"

void destroy_shop_spt(shop_t *shop)
{
    sfSprite_destroy(shop->shop_spt);
}

void destroy_shop_tex(shop_t *shop)
{
    sfTexture_destroy(shop->shop_tex);
}

void destroy_enemy_tex(enemy_t *enemy)
{
    sfTexture_destroy(enemy->pirat->pirat_txt);
}

void destroy_enemy_spt(enemy_t *enemy)
{
    sfSprite_destroy(enemy->pirat->pirat_spt);
}