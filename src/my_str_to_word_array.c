/*
** EPITECH PROJECT, 2021
** B-AIA-200-STG-2-1-n4s-elliot.waldvogel
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/my.h"

void turn_car(int wall, nfors_t *nfs)
{
    if (wall > 1000)
    {
        dprintf(1, "WHEELS_DIR:1\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    else if (wall > 500)
    {
        dprintf(1, "WHEELS_DIR:0.3\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    else if (wall > 250)
    {
        dprintf(1, "WHEELS_DIR:0.2\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    else if (wall > 0)
    {
        dprintf(1, "WHEELS_DIR:0\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    if (wall < -1000)
    {
        dprintf(1, "WHEELS_DIR:-1\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    else if (wall < -500)
    {
        dprintf(1, "WHEELS_DIR:-0.5\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    else if (wall < 0)
    {
        dprintf(1, "WHEELS_DIR:-0.1\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    /*if (wall > -300 && wall < 300) {
        dprintf(1, "WHEELS_DIR:0.0\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }*/
}

void break_car(nfors_t *nfs)
{
    dprintf(1, "Car_forward:0.3\n");
    order_line(nfs);
    dprintf(1, "Cycle_wait:1\n");
    order_line(nfs);

    /*if ((abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) >= 250) && (abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) < 300)) {
        dprintf(1, "WHEELS_DIR:");
        if (dir < 0)
            dprintf(1, '-');
        dprintf(1, "0.05\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if ((abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) >= 350) && (abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) < 400)) {
        dprintf(1, "WHEELS_DIR:");
        if (dir < 0)
            dprintf(1, '-');
        dprintf(1, "0.1\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if ((abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) >= 400) && (abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33] < 450)))) {
        dprintf(1, "WHEELS_DIR:");
        if (dir < 0)
            dprintf(1, '-');
        dprintf(1, "0.2\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if ((abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) >= 450) && (abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33] < 500)))) {
        dprintf(1, "WHEELS_DIR:");
        if (dir < 0)
            dprintf(1, '-');
        dprintf(1, "0.3\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if ((abs(atof(nfs->my_tab[3])) - abs(atof(nfs->my_tab[33])) >= 600)) {
        dprintf(1, "WHEELS_DIR:");
        if (dir < 0)
            dprintf(1, '-');
        dprintf(1, "0.5\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }*/
    float angle = 0;
    nfs->avoiding = 0;
    nfs->avoid_mul = 0;

    //right front radar
    if (atof(nfs->my_tab[19]) < 100)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul -= 0.6;
    }
    //right mid radar
    else if (atof(nfs->my_tab[11]) < 350 && atof(nfs->my_tab[19]) < 200)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul -= 0.27;
    }
    else if (atof(nfs->my_tab[6]) < 385 && atof(nfs->my_tab[19]) < 450)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul -= 0.23;
    }
    //right side radar
    else if (atof(nfs->my_tab[3]) < 425)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul -= 0.2;
    }

    //left front radar
    else if (atof(nfs->my_tab[20]) < 100)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul += 0.6;
    }
    //left mid radar
    else if (atof(nfs->my_tab[27]) < 350 && atof(nfs->my_tab[20]) < 300)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul += 0.27;
    }
    else if (atof(nfs->my_tab[31]) < 385 && atof(nfs->my_tab[20]) < 450)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul += 0.23;
    }
    // left side radar
    else if (atof(nfs->my_tab[34]) < 425)
    {
        nfs->avoiding = 1;
        nfs->avoid_mul += 0.2;
    }

    if (nfs->avoiding == 1)
    {
        angle = 1 * nfs->avoid_mul;
        dprintf(1, "WHEELS_DIR:%f\n", angle);
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
        dprintf(2, "WHEELS_DIR%f\n", angle);
    }

    /*
    if (atof(nfs->my_tab[33]) < 450 && atof(nfs->my_tab[33]) >= 350) {
        dprintf(1, "WHEELS_DIR:0.1\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (atof(nfs->my_tab[33]) < 350 && atof(nfs->my_tab[33]) >= 200) {
        dprintf(1, "WHEELS_DIR:0.3\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (atof(nfs->my_tab[33]) < 200 && atof(nfs->my_tab[33]) >= 100) {
        dprintf(1, "WHEELS_DIR:0.35\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if ((atof(nfs->my_tab[33]) < 100) && (atof(nfs->my_tab[33]) >= 50)) {
        dprintf(1, "WHEELS_DIR:0.4\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (atof(nfs->my_tab[33]) < 50) {
        dprintf(1, "WHEELS_DIR:0.45\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    if (atof(nfs->my_tab[3]) < 450 && atof(nfs->my_tab[3]) >= 350) {
        dprintf(1, "WHEELS_DIR:-0.1\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (atof(nfs->my_tab[3]) < 350 && atof(nfs->my_tab[3]) >= 200) {
        dprintf(1, "WHEELS_DIR:-0.3\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (atof(nfs->my_tab[3]) < 200 && atof(nfs->my_tab[3]) >= 100) {
        dprintf(1, "WHEELS_DIR:-0.35\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if ((atof(nfs->my_tab[3]) < 100) && (atof(nfs->my_tab[3]) >= 50)) {
        dprintf(1, "WHEELS_DIR:-0.4\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (atof(nfs->my_tab[3]) < 50) {
        dprintf(1, "WHEELS_DIR:-0.45\n");
        order_line(nfs);
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } */
}

/*void function(stumper_t *stp)
{
    for (int stp->star[i] = 0; i != '\0'; i++)
}*/

/*void break_car(nfors_t *nfs)
{
    // if (nfs->stop == 1) {
    //     //dprintf(1, "Car_backwards:1\n");
    //     dprintf(1, "Car_forward:0.0\n");
    //     order_line(nfs);
    //     dprintf(2, "STOOOOP\n");
    //     //dprintf(1, "Cycle_wait:10\n");
    // }
    if (nfs->stop == 0) {
        dprintf(1, "Car_forward:0.3\n");
        order_line(nfs);
        dprintf(2, "FORWARD\n");
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    dprintf(2, "right = %i et left = %i", nfs->average_left, nfs->average_right);
    if (nfs->average_right < 400 && nfs->average_lastright >= nfs->average_right) {
        dprintf(1, "WHEELS_DIR:0.4\n");
        order_line(nfs);
        nfs->average_lastright = nfs->average_right;
        nfs->wheel = 1;
    } else if (nfs->wheel == 1) {
        dprintf(1, "WHEELS_DIR:0\n");
        dprintf(2, "WHEELS_DIR:0\n");
        order_line(nfs);
        nfs->wheel = 0;
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    if (nfs->average_left < 400 && nfs->average_lastleft >= nfs->average_left) {
        dprintf(1, "WHEELS_DIR:-0.4\n");
        order_line(nfs);
        nfs->wheel = 1;
        printf(1, "Cycle_wait:1\n");
        order_line(nfs);
    } else if (nfs->wheel == 1) {
        dprintf(1, "WHEELS_DIR:0\n");
        dprintf(2, "WHEELS_DIR:0\n");
        order_line(nfs);
        nfs->wheel = 0;
        dprintf(1, "Cycle_wait:1\n");
        order_line(nfs);
    }
    //dprintf(2, "right = %i et left = %i", nfs->average_left, nfs->average_right);
    // if (nfs->average_left > nfs->average_right && nfs->wheel == 1) {
    //     dprintf(1, "WHEELS_DIR:0");
    //     order_line(nfs);
    //     nfs->wheel = 0;
    // }
    dprintf(2, "SPEED = %i\n", my_tab[4]);
    if (atoi(my_tab[3]) > 30)
        dprintf(1, "CAR_FORWARD:0\n");
}*/

char **malloc_double(char *str, int space)
{
    char **my_tab;
    int p = 0;

    my_tab = malloc(sizeof(char *) * (space + 2));
    for (; p < space; p++)
        my_tab[p] = malloc(sizeof(char) * (my_strlen(str) + 2));
    my_tab[p] = NULL;
    return (my_tab);
}

void my_str_to_word_array(char *str, nfors_t *nfs)
{
    //nfs->my_tab = malloc(sizeof(char *) * 7);
    nfs->tab_len = 1;
    int x = 0;
    int y = 0;

    //dprintf(2, "C'EST LE PRINTF = %s\n", str);
    for (int z = 0; str[z]; z++)
        if (str[z] == ':')
            nfs->tab_len++;
    if (nfs->tab_len > 15)
    {
        nfs->my_tab = malloc_double(str, nfs->tab_len);
        for (int i = 0; x <= (nfs->tab_len - 1); x++)
        {
            for (; str[i] != ':' && str[i] != '\n'; i++)
            {
                nfs->my_tab[x][y] = str[i];
                dprintf(2, "%c", nfs->my_tab[x][y]);
                y++;
            }
            dprintf(2, ":");
            nfs->my_tab[x][y] = '\0';
            i++;
            y = 0;
        }
        dprintf(2, "\n");
    }
}
