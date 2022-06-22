/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_tuto
*/

#include "../../../include/func_name.h"

static void init_tuto2(rpg_t *rpg)
{
    sfTexture *tuto4 = sfTexture_createFromFile
    ("assets/tutorial/tutoriel4.png", NULL);
    sfTexture *tuto5 = sfTexture_createFromFile
    ("assets/tutorial/tutoriel5.png", NULL);

    sfSprite_setTexture(rpg->tutorial->instruct[TUTO4],
    tuto4, sfTrue);
    sfSprite_setTexture(rpg->tutorial->instruct[TUTO5],
    tuto5, sfTrue);
}

void init_map_tuto(rpg_t *rpg)
{
    sfTexture *map = sfTexture_createFromFile
    ("assets/tutorial/maps/tutoriel.png", NULL);
    rpg->game->in_game->map->collisions[MAP_TUTO] = sfImage_createFromFile
    ("assets/tutorial/maps/colisions.png");
    sfVector2f pos = {0, -30};

    rpg->game->in_game->inventory->is_item_selected = FALSE;
    rpg->game->in_game->map->pos_map[MAP_TUTO] = put_in_vector2f(-1809, -1027);
    sfSprite_setTexture(rpg->game->in_game->map->maps[MAP_TUTO],
    map, sfTrue);
    sfSprite_setPosition(rpg->game->in_game->map->maps[MAP_TUTO],
    rpg->game->in_game->map->pos_map[MAP_TUTO]);
    for (int i = TUTO1; i != TUTO5; i++)
        sfSprite_setPosition(rpg->tutorial->instruct[i], pos);
    rpg->game->in_game->map->tex_size_map[MAP_TUTO] =
    sfTexture_getSize(map);
}

int init_tuto(rpg_t *rpg)
{
    sfTexture *tuto1 = sfTexture_createFromFile
    ("assets/tutorial/tutoriel1.png", NULL);
    sfTexture *tuto2 = sfTexture_createFromFile
    ("assets/tutorial/tutoriel2.png", NULL);
    sfTexture *tuto3 = sfTexture_createFromFile
    ("assets/tutorial/tutoriel3.png", NULL);

    if ((rpg->tutorial->instruct = malloc(sizeof(sfSprite *) * 5)) == NULL)
        return (MALLOC_ERROR);
    for (int i = TUTO1; i <= TUTO5; i++)
        rpg->tutorial->instruct[i] = sfSprite_create();
    init_tuto2(rpg);
    sfSprite_setTexture(rpg->tutorial->instruct[TUTO1],
    tuto1, sfTrue);
    sfSprite_setTexture(rpg->tutorial->instruct[TUTO2],
    tuto2, sfTrue);
    sfSprite_setTexture(rpg->tutorial->instruct[TUTO3],
    tuto3, sfTrue);
    return (0);
}