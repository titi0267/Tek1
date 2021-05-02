/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** init_inventory.c
*/

#include "../../../include/func_name.h"

void set_inventory_sprites(rpg_t *rpg)
{
    for (int i = SMG; i < NO_WEAPON; i++) {
        rpg->game->in_game->inventory->weapon[i] = sfSprite_create();
        sfSprite_setTexture(rpg->game->in_game->inventory->weapon[i],
        rpg->game->in_game->inventory->weapon_txt[i], sfTrue);
    }
    for (int i = WEAPON; i < NO_SLOT; i++)
        rpg->game->in_game->inventory->is_area_filled[i] = FALSE;
}

void init_positions(rpg_t *rpg)
{
    rpg->game->in_game->inventory->pos_storage[WEAPON] =
    put_in_vector2f(370.5, 366.5);
    rpg->game->in_game->inventory->pos_storage[AMMO] =
    put_in_vector2f(370.5, 456.833);
    rpg->game->in_game->inventory->pos_storage[VEST] =
    put_in_vector2f(370.5, 637.5);
    rpg->game->in_game->inventory->pos_weapon[SMG] =
    put_in_vector2f(825.5, 421.5);
    rpg->game->in_game->inventory->pos_weapon[KNIFE] =
    put_in_vector2f(916.5, 421.5);
    rpg->game->in_game->inventory->pos_weapon[GUN] =
    put_in_vector2f(1007.5, 421.5);
    rpg->game->in_game->inventory->pos_weapon[TAZER] =
    put_in_vector2f(1098.5, 421.5);
}

void init_inventory(rpg_t *rpg)
{
    rpg->game->in_game->inventory->pos_weapon = malloc(sizeof(sfVector2f) * 4);
    rpg->game->in_game->inventory->pos_storage = malloc(sizeof(sfVector2f) * 3);
    rpg->game->in_game->inventory->inventory = sfSprite_create();
    rpg->game->in_game->inventory->inventory_txt =
    sfTexture_createFromFile("assets/inventory/inventaire.png", NULL);
    sfSprite_setTexture(rpg->game->in_game->inventory->inventory,
    rpg->game->in_game->inventory->inventory_txt, sfTrue);
    rpg->game->in_game->inventory->is_area_filled = malloc(sizeof(int) * 3);
    rpg->game->in_game->inventory->weapon = malloc(sizeof(sfSprite *) * 4);
    rpg->game->in_game->inventory->weapon_txt = malloc(sizeof(sfTexture *) * 4);
    rpg->game->in_game->inventory->weapon_txt[SMG] =
    sfTexture_createFromFile("assets/inventory/mitraillette.png", NULL);
    rpg->game->in_game->inventory->weapon_txt[KNIFE] =
    sfTexture_createFromFile("assets/inventory/knife.png", NULL);
    rpg->game->in_game->inventory->weapon_txt[GUN] =
    sfTexture_createFromFile("assets/inventory/pistolet.png", NULL);
    rpg->game->in_game->inventory->weapon_txt[TAZER] =
    sfTexture_createFromFile("assets/inventory/tazer.png", NULL);
    init_positions(rpg);
    set_inventory_sprites(rpg);
    rpg->game->in_game->inventory->selected_item = NO_WEAPON;
}