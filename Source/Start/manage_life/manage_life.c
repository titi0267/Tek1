/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** manage_life
*/

#include "../../../include/defender.h"

int my_strlen(char *str)
{
    int nb = 0;

    for (int i = 0; str[i] != '\0'; i++)
        nb++;
    return (nb);
}

char *rev_str(char *str)
{
    char temp;
    int i = 0;
    int j = my_strlen(str) - 1;

    while (i <= j) {
    if (str[i] == '-') {
        str[i] = '-';
        i++;
    }
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return (str);
}

char *my_itoa(int r, char *result)
{
    int i = 0;
    int j;

    if ((j = r) < 0)
        r = -r;
    r *= 10;
    result[i] = r % 10 + '0';
    while ((r /= 10) > 0)
        result[i++] = r % 10 + '0';
    if (j < 0)
        result[i++] = '-';
    else if (r == 0) {
        result[i] = '0';
        i++;
    }
    result[i] = '\0';
    rev_str(result);
    return (result);
}

int manage_wave(core_t *core)
{
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->wave->nb_wave;
    char *scr = malloc(sizeof(char) * 4);
    scr = my_itoa(i, scr);
    sfColor color = sfBlack;
    sfVector2f pos_score = {1800, 950};
    sfVector2f scale_score = {1.5, 1.5};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    return (0);
}

int manage_life(core_t *core)
{
    sfFont *Font = sfFont_createFromFile("Ressources/FONT/Early GameBoy.ttf");
    int i = core->game->lifepoint;
    char *scr = malloc(sizeof(char) * 4);
    scr = my_itoa(i, scr);
    sfColor color = sfBlack;
    sfVector2f pos_score = {100, 0};
    sfVector2f scale_score = {1.5, 1.5};

    sfText_setFont(core->game->life, Font);
    sfText_setString(core->game->life, scr);
    sfText_setColor(core->game->life, color);
    sfText_setPosition(core->game->life, pos_score);
    sfText_setScale(core->game->life, scale_score);
    sfRenderWindow_drawText(core->wnd->window, core->game->life, NULL);
    free(scr);
    return (0);
}