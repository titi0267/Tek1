/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** init_options_gs
*/

#include "../../../include/func_name.h"

void create_size_square(rpg_t *rpg)
{
    rpg->main_menu->graphismes = malloc(sizeof(sfSprite *) * 8);
    rpg->main_menu->fill_square = sfTexture_createFromFile
    ("assets/menus/options/shape.png", NULL);
    rpg->main_menu->empty_square = sfTexture_createFromFile
    ("assets/menus/options/empty_shape.png", NULL);

    rpg->main_menu->graphismes[RES19x80] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->graphismes[RES19x80],
    rpg->main_menu->empty_square, sfTrue);
    rpg->main_menu->graphismes[RES12x20] =
    sfSprite_copy(rpg->main_menu->graphismes[RES19x80]);
    rpg->main_menu->graphismes[RES11x30] =
    sfSprite_copy(rpg->main_menu->graphismes[RES19x80]);
    rpg->main_menu->graphismes[FPS30] =
    sfSprite_copy(rpg->main_menu->graphismes[RES19x80]);
    rpg->main_menu->graphismes[FPS60] =
    sfSprite_copy(rpg->main_menu->graphismes[RES19x80]);
}

void init_bt_opt(rpg_t *rpg)
{
    sfVector2f fps_30 = {1477.554, 382.25};
    sfVector2f fps_60 = {1631.554, 382.25};
    sfVector2f res_19x80 = {1589.804, 613.25};
    sfVector2f res_12x20 = {1589.804, 571.75};
    sfVector2f res_11x30 = {1589.804, 530.25};
    sfVector2f music = {1565.554, 363};
    sfVector2f ambiant = {1565.554, 510};
    sfVector2f diag = {1565.554, 657};

    sfSprite_setPosition(rpg->main_menu->graphismes[RES19x80], res_19x80);
    sfSprite_setPosition(rpg->main_menu->graphismes[RES12x20], res_12x20);
    sfSprite_setPosition(rpg->main_menu->graphismes[RES11x30], res_11x30);
    sfSprite_setPosition(rpg->main_menu->graphismes[FPS30], fps_30);
    sfSprite_setPosition(rpg->main_menu->graphismes[FPS60], fps_60);
    sfSprite_setPosition(rpg->main_menu->graphismes[CIRCLE_MUSIC], music);
    sfSprite_setPosition(rpg->main_menu->graphismes[CIRCLE_AMBT], ambiant);
    sfSprite_setPosition(rpg->main_menu->graphismes[CIRCLE_DIAG], diag);
}

void sound_cirle(rpg_t *rpg)
{
    sfTexture *circle = sfTexture_createFromFile
    ("assets/menus/options/circle_sound.png", NULL);

    rpg->main_menu->graphismes[CIRCLE_MUSIC] = sfSprite_create();
    sfSprite_setTexture(rpg->main_menu->graphismes[CIRCLE_MUSIC],
    circle, sfTrue);
    rpg->main_menu->graphismes[CIRCLE_DIAG] =
    sfSprite_copy(rpg->main_menu->graphismes[CIRCLE_MUSIC]);
    rpg->main_menu->graphismes[CIRCLE_AMBT] =
    sfSprite_copy(rpg->main_menu->graphismes[CIRCLE_MUSIC]);
}