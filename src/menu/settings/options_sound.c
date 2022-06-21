/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** options_sound
*/

#include "../../../include/func_name.h"

void set_volume(rpg_t *rpg)
{
    sfVector2f pos_music = sfSprite_getPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC]);
    float volume_music = vol_checker(pos_music.x);
    sfVector2f pos_dial = sfSprite_getPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG]);
    float volume_dial = vol_checker(pos_dial.x);
    sfVector2f pos_amb = sfSprite_getPosition
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT]);
    float volume_amb = vol_checker(pos_amb.x);

    sfSound_setVolume(rpg->menu->main_menu->menu_snd->a_menu, volume_music);
    sfSound_setVolume(rpg->game->end->cinematic_2, volume_dial);
    sfSound_setVolume(rpg->game->start->cinematic_1, volume_dial);
    sfSound_setVolume(rpg->game->in_game->ig_sound->riley, volume_dial);
    sfSound_setVolume(rpg->game->in_game->ig_sound->riley_call, volume_dial);
    sfSound_setVolume(rpg->game->in_game->ig_sound->riley_warren, volume_dial);
    sfSound_setVolume(rpg->tutorial->tuto, volume_amb);
    sfSound_setVolume(rpg->game->in_game->ig_sound->game, volume_amb);
    sfSound_setVolume(rpg->game->in_game->phone->notif_sound, volume_amb);
    sfSound_setVolume(rpg->game->in_game->phone->call_sound, volume_amb);
    sfSound_setVolume(rpg->game->in_game->objects->car->sirene, volume_amb);
}

void manage_music(rpg_t *rpg, sfFloatRect music, sfVector2f mouse)
{
    sfVector2f sp_center = {music.width / 2, music.height / 2};

    sfSprite_setOrigin
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC], sp_center);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC], NULL);
    mouse.y = 363;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, music.left - 67)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, music.top - 67)) &&
        (rpg->basic->cnf->mouse.x <=
        adapt_x(rpg, music.left + music.width + 67)) &&
        (rpg->basic->cnf->mouse.y <=
        adapt_y(rpg, music.top + music.height + 67)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1679.393) &&
        (rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1453)))
            sfSprite_setPosition
            (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC],
            mouse);
    }
}

void manage_dial(rpg_t *rpg, sfFloatRect dial, sfVector2f mouse)
{
    sfVector2f sp_center = {dial.width / 2, dial.height / 2};

    sfSprite_setOrigin
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG], sp_center);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG], NULL);
    mouse.y = 657;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, dial.left - 67)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, dial.top - 67)) &&
        (rpg->basic->cnf->mouse.x <=
        adapt_x(rpg, dial.left + dial.width + 67)) &&
        (rpg->basic->cnf->mouse.y <=
        adapt_y(rpg, dial.top + dial.height + 67)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1678.51) &&
        (rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1452.608)))
            sfSprite_setPosition
            (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG], mouse);
    }
}

void manage_amb(rpg_t *rpg, sfFloatRect amb, sfVector2f mouse)
{
    sfVector2f sp_center = {amb.width / 2, amb.height / 2};

    sfSprite_setOrigin
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT], sp_center);
    sfRenderWindow_drawSprite(rpg->basic->wnd->my_wnd,
    rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT], NULL);
    mouse.y = 510;
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (((rpg->basic->cnf->mouse.x) >= adapt_x(rpg, amb.left - 67)) &&
        ((rpg->basic->cnf->mouse.y) >= adapt_y(rpg, amb.top - 67)) &&
        (rpg->basic->cnf->mouse.x <=
        adapt_x(rpg, amb.left + amb.width + 67)) &&
        (rpg->basic->cnf->mouse.y <=
        adapt_y(rpg, amb.top + amb.height + 67)) &&
        (rpg->basic->cnf->mouse.x <= adapt_x(rpg, 1678.51) &&
        (rpg->basic->cnf->mouse.x) >= adapt_x(rpg, 1452.608)))
            sfSprite_setPosition
            (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT], mouse);
    }
}

void manage_sound(rpg_t *rpg)
{
    sfFloatRect music = sfSprite_getGlobalBounds
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_MUSIC]);
    sfFloatRect dial = sfSprite_getGlobalBounds
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_DIAG]);
    sfFloatRect amb = sfSprite_getGlobalBounds
    (rpg->menu->stg->graph->graph_btn->graphismes[CIRCLE_AMBT]);
    sfVector2f mouse = sfRenderWindow_mapPixelToCoords(rpg->basic->wnd->my_wnd,
    sfMouse_getPositionRenderWindow(rpg->basic->wnd->my_wnd), NULL);

    manage_music(rpg, music, mouse);
    manage_dial(rpg, dial, mouse);
    manage_amb(rpg, amb, mouse);
    set_volume(rpg);
}