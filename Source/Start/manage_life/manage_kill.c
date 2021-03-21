/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_kill
*/

#include "../../../include/defender.h"

void init_spt_ingame_bis(core_t *core)
{
    sfVector2f pos = {330, 8};
    sfVector2f scale = {0.1 , 0.1};

    core->game->money_text = sfTexture_createFromFile(
        "Ressources/FONT/money.png", sfFalse);
    core->game->money_spt = sfSprite_create();
    sfSprite_setTexture(core->game->money_spt,
        core->game->money_text, sfFalse);
    sfSprite_setPosition(core->game->money_spt, pos);
    sfSprite_setScale(core->game->money_spt, scale);
}

void init_spt_ingame(core_t *core)
{
    sfVector2f pos = {50, 10};
    sfVector2f pos2 = {10, 940};
    sfVector2f scale = {0.1, 0.1};
    sfVector2f scale2 = {0.05, 0.05};

    core->game->health_txt =
        sfTexture_createFromFile("Ressources/FONT/health.png", sfFalse);
    core->game->deadhead_txt =
        sfTexture_createFromFile("Ressources/FONT/dead_head.png", sfFalse);
    core->game->health = sfSprite_create();
    core->game->deadhead = sfSprite_create();
    sfSprite_setTexture(core->game->health, core->game->health_txt, sfFalse);
    sfSprite_setTexture(core->game->deadhead,
        core->game->deadhead_txt, sfFalse);
    sfSprite_setPosition(core->game->health, pos);
    sfSprite_setPosition(core->game->deadhead, pos2);
    sfSprite_setScale(core->game->deadhead, scale);
    sfSprite_setScale(core->game->health, scale2);
    init_spt_ingame_bis(core);
}

int manage_kill(core_t *core)
{
    lib_t *lib = malloc(sizeof(lib_t));
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->wave->kill;
    char *scr = my_int_str(i, lib);
    sfColor color = sfBlack;
    sfVector2f pos_score = {80, 950};
    sfVector2f scale_score = {1.5, 1.5};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    free(lib);
    return (0);
}