/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_options_gs
*/

#include "../../../include/func_name.h"

void create_size_square(rpg_t *rpg)
{
    rpg->menu->stg->graph->graph_btn->graphismes =
    malloc(sizeof(sfSprite *) * 8);
    rpg->menu->stg->graph->graph_btn->fill_square = sfTexture_createFromFile
    ("assets/menus/options/shape.png", NULL);
    rpg->menu->stg->graph->graph_btn->empty_square = sfTexture_createFromFile
    ("assets/menus/options/empty_shape.png", NULL);
    rpg->menu->stg->graph->graph_btn->graphismes[RES19x80] = sfSprite_create();
    sfSprite_setTexture(rpg->menu->stg->graph->graph_btn->graphismes[RES19x80],
    rpg->menu->stg->graph->graph_btn->empty_square, sfTrue);
    rpg->menu->stg->graph->graph_btn->graphismes[RES12x20] =
    sfSprite_copy(rpg->menu->stg->graph->graph_btn->graphismes[RES19x80]);
    rpg->menu->stg->graph->graph_btn->graphismes[RES11x30] =
    sfSprite_copy(rpg->menu->stg->graph->graph_btn->graphismes[RES19x80]);
    rpg->menu->stg->graph->graph_btn->graphismes[FPS30] =
    sfSprite_copy(rpg->menu->stg->graph->graph_btn->graphismes[RES19x80]);
    rpg->menu->stg->graph->graph_btn->graphismes[FPS60] =
    sfSprite_copy(rpg->menu->stg->graph->graph_btn->graphismes[RES19x80]);
}

static void init_bt_opt2(rpg_t *rpg)
{
    sfVector2f music = {1565.554, 363};
    sfVector2f ambiant = {1565.554, 510};
    sfVector2f diag = {1565.554, 657};
    sfVector2f fps_60 = {1631.554, 382.25};

    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[FPS60], fps_60);
    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC], music);
    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT], ambiant);
    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG], diag);
}

void init_bt_opt(rpg_t *rpg)
{
    sfVector2f fps_30 = {1477.554, 382.25};
    sfVector2f res_19x80 = {1589.804, 613.25};
    sfVector2f res_12x20 = {1589.804, 571.75};
    sfVector2f res_11x30 = {1589.804, 530.25};

    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[RES19x80], res_19x80);
    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[RES12x20], res_12x20);
    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[RES11x30], res_11x30);
    sfSprite_setPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[FPS30], fps_30);
    init_bt_opt2(rpg);
}

void sound_cirle(rpg_t *rpg)
{
    sfTexture *circle = sfTexture_createFromFile
    ("assets/menus/options/circle_sound.png", NULL);

    rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC] =
    sfSprite_create();
    sfSprite_setTexture
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC],
    circle, sfTrue);
    rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG] =
    sfSprite_copy(rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC]);
    rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT] =
    sfSprite_copy(rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC]);
}