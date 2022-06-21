/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-timothe.coniel
** File description:
** reset_duck
*/
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/my_struct.h"
#include "../include/my.h"

void restart(sfRenderWindow *window, sfEvent *event, duck_t *pos)
{
    if (click(window, event, pos) == 2) {
        pos->position.x = -120;
        pos->position.y = 0;
        pos->offset = 0;
    }
    else
        click(window, event, pos);
}

void edge_window(sfRenderWindow *window, duck_t *pos)
{

    if (pos->position.x >= 904) {
        sfSprite_setPosition(pos->my_duck_straight, pos->position);
        pos->position.x = -110;
        pos->position.y = 0;
    }
    else {
        pos->position.x += 4;
        pos->position.y += 1;
    }
}