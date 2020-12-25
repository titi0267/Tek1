/*
** EPITECH PROJECT, 2020
** Collision by Timothy CONIEL
** File description:
** collision.c
*/
#include "../include/my.h"

void init_pipe(enemy_t *enemy, map_t *buff, sfRenderWindow *window)
{
    int c = 0;
    int l = 0;

    enemy->enemy_pos.y = 0;
    enemy->enemy_pos.x = 0;
    for (; l != 11; l++) {
        for (; buff->line[l][c] != '\0'; c++) {
            if (buff->line[l][c] == '\n') {
                enemy->enemy_pos.y = 0;
                enemy->enemy_pos.x = 0;
            }
            if (buff->line[l][c] == ' ' && (c % 8) != 0) {
                enemy->enemy_pos.x = enemy->enemy_pos.x + 60;
            }
            if (buff->line[l][c] == ' ' && (c % 8) == 0) {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
            }
            if (buff->line[l][c] == '2' || buff->line[l][c] == '3') {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
                enemy->enemy_pos.y = (l - 1) * 84;
                sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos);
                sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
            }
        }
        c = 0;
    }
    /*enemy->enemy_pos2.x = 1400;
    enemy->enemy_pos2.y = 84;
    enemy->enemy_pos3.x = 1400;
    enemy->enemy_pos3.y = 666;
    enemy->enemy_pos4.x = 1400;
    enemy->enemy_pos4.y = 582;
    enemy->enemy_pos5.x = 1400;
    enemy->enemy_pos5.y = 498;
    enemy->enemy_pos6.x = 1400;
    enemy->enemy_pos6.y = 168;
    enemy->enemy_pos7.x = 1400;
    enemy->enemy_pos7.y = 252;
    enemy->enemy_pos8.x = 1400;
    enemy->enemy_pos8.y = 336;*/
}

/*void create_enemys(enemy_t *enemy)
{
    enemy->my_pipe2 = enemy->my_pipe;
}*/

void pipe_sprite(sfRenderWindow *window, enemy_t *enemy, map_t *buff)
{
    enemy->pipe_tex = sfTexture_createFromFile("png/begin_pipe.png", NULL);
    enemy->my_pipe = sfSprite_create();
    sfVector2f scale = {1, 1};

    //sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos);
    sfSprite_setTexture(enemy->my_pipe, enemy->pipe_tex, sfFalse);
    sfSprite_setScale(enemy->my_pipe, scale);
    init_pipe(enemy, buff, window);
    //sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    /*sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos2);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos3);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos4);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos5);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos6);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos7);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
    sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos8);
    sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);*/
    sfSprite_destroy(enemy->my_pipe);
    sfTexture_destroy(enemy->pipe_tex);
}

void enemy_speed(float delta_time, map_t *buff, player_t *bird, enemy_t *enemy, sfRenderWindow *window)
{
    static float enmy = 0;
/*    int l = 0;
    int c = 0;

    for (; buff->line[l][c] != '\0'; c++) {
            if (buff->line[l][c] == '\n') {
                l = l + 1;
                c = 0;
            }
            if (buff->line[l][c] == ' ') {
                enemy->enemy_pos.x = enemy->enemy_pos.x + 20;
            }
            if (buff->line[l][c] == '2') {
                enemy->enemy_pos.x = enemy->enemy_pos.x;
                enemy->enemy_pos.y = l * 84;
                sfSprite_setPosition(enemy->my_pipe, enemy->enemy_pos);
                sfRenderWindow_drawSprite(window, enemy->my_pipe, NULL);
            }
    //map_limit(buff, bird, enemy, window);
    }*/
    if (enmy >= 0.01f) {

        enmy = 0;
    }
    enmy = delta_time + enmy;
    /*                enemy->enemy_pos.x = enemy->enemy_pos.x - 1;
                enemy->enemy_pos2.x = enemy->enemy_pos2.x - 1;
                enemy->enemy_pos3.x = enemy->enemy_pos3.x - 1;
                enemy->enemy_pos4.x = enemy->enemy_pos4.x - 1;
                enemy->enemy_pos5.x = enemy->enemy_pos5.x - 1;
                enemy->enemy_pos6.x = enemy->enemy_pos6.x - 1;
                enemy->enemy_pos7.x = enemy->enemy_pos7.x - 1;
                enemy->enemy_pos8.x = enemy->enemy_pos8.x - 1;
    */
}

/*void map_limit(map_t *buff, player_t *bird, enemy_t *enemy, sfRenderWindow *window)
{
    //int c = 0;
    int l = 0;

    for (; l != 11; l++) {
        for (int c = 0; buff->line[l][c] != '\0'; c++) {
            //if (buff->line[0][c] == '1')
            //    printf("Is one\n");
                //bird->collision_up.y = 0;
            /*if (buff->line[10][c] == '1')
                bird->collision_down.y = 750;
            if (buff->line[l][c] == '\n') {

                enemy->enemy_pos.y = enemy->enemy_pos.y + 1;
                //enemy->enemy_pos.y = ((750 / 9) + enemy->enemy_pos.y);
            }
            /*if (buff->line[l][c] == ' ') {
                enemy->enemy_pos.x = enemy->enemy_pos.x + 1;
            }*/
            /*if (buff->line[l][c] == '2') {
                enemy->enemy_pos.x = enemy->enemy_pos.x - 1;
                //enemy->enemy_pos.x = enemy->enemy_pos.x + 100;
            }
            //if (buff->line[l][c + 1] == '\0')
            //    l++;
        }
    }
}*/