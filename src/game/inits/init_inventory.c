/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_inventory.c
*/

#include "../../../include/func_name.h"

void init_inventory(rpg_t *rpg)
{
    rpg->game->in_game->inventory->pos_weapon = malloc(sizeof(sfVector2f) * 5);
    rpg->game->in_game->inventory->inventory = sfSprite_create();
    rpg->game->in_game->inventory->inventory_txt =
    sfTexture_createFromFile("assets/inventory/inventaire.png", NULL);
    sfSprite_setTexture(rpg->game->in_game->inventory->inventory,
    rpg->game->in_game->inventory->inventory_txt, sfTrue);
    rpg->game->in_game->inventory->weapon = malloc(sizeof(sfSprite *) * 5);
    rpg->game->in_game->inventory->weapon_txt = malloc(sizeof(sfTexture *) * 5);
    rpg->game->in_game->inventory->weapon_txt[SMG] = sfTexture_createFromFile(
    "assets/inventory/mitraillette.png", NULL);
    rpg->game->in_game->inventory->weapon_txt[KNIFE] = sfTexture_createFromFile(
    "assets/inventory/knife.png", NULL);
    rpg->game->in_game->inventory->weapon_txt[GUN] = sfTexture_createFromFile(
    "assets/inventory/pistolet.png", NULL);
    rpg->game->in_game->inventory->weapon_txt[TAZER] = sfTexture_createFromFile(
    "assets/inventory/tazer.png", NULL);
    for (int i = SMG; i < NO_WEAPON; i++) {
        rpg->game->in_game->inventory->weapon[i] = sfSprite_create();
        sfSprite_setTexture(rpg->game->in_game->inventory->weapon[i],
        rpg->game->in_game->inventory->weapon_txt[i], sfTrue);
    }
}