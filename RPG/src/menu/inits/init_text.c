/*
** EPITECH PROJECT, 2021
** init_text
** File description:
** init_text
*/

#include "../../../include/func_name.h"

int malloc_text(menu_t *menu)
{
    if ((menu->stg->key_bnd->control = malloc(sizeof(control_t *) *
    (QUADCOPTER + 1))) == NULL)
        return (MALLOC_ERROR);
    for (int i = 0; i <= QUADCOPTER; i++) {
        if ((menu->stg->key_bnd->control[i] =
        malloc(sizeof(control_t))) == NULL)
            return (MALLOC_ERROR);
        menu->stg->key_bnd->control[i]->text = malloc(sizeof(char) * 10);
    }
    return (0);
}

static void set_text_pos(rpg_t *rpg)
{
    sfVector2f vect = {1542, 242};
    int i = 0;

    for (; i <= RUN; i++) {
        sfText_setPosition(rpg->menu->stg->key_bnd->control[i]->box,
        vect);
        vect.y += 66;
    }
    vect.y += 22;
    sfText_setPosition(rpg->menu->stg->key_bnd->control[i]->box, vect);
    vect.y += 85;
    i++;
    for (; i <= QUADCOPTER; i++) {
        sfText_setPosition(rpg->menu->stg->key_bnd->control[i]->box,
        vect);
        vect.y += 64;
    }
}

void init_text(rpg_t *rpg)
{
    sfFont *font;

    font = sfFont_createFromFile("assets/fonts/aqua.ttf");
    for (int i = 0; i <= QUADCOPTER; i++) {
        rpg->menu->stg->key_bnd->control[i]->box = sfText_create();
        sfText_setFont(rpg->menu->stg->key_bnd->control[i]->box, font);
        sfText_setCharacterSize(
        rpg->menu->stg->key_bnd->control[i]->box, 20);
        sfText_setString(rpg->menu->stg->key_bnd->control[i]->box,
        rpg->menu->stg->key_bnd->control[i]->text);
    }
    set_text_pos(rpg);
}