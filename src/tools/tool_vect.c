/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-myrpg-timothe.coniel
** File description:
** tools
*/

#include "../../include/func_name.h"

int point_distcance(sfVector2f mouse, sfVector2f map)
{
    int distancenew = sqrt(((map.x - mouse.x) * (map.x - mouse.x) / 2) +
    (map.y - mouse.y) * (map.y - mouse.y));

    return (distancenew);
}

sfVector2f put_in_vector2f(float x, float y)
{
    sfVector2f pos = {x, y};

    return (pos);
}

sfVector2u put_in_vector2u(unsigned int x, unsigned int y)
{
    sfVector2u pos = {x, y};

    return (pos);
}

sfVector2f vect_diff(sfVector2f first, sfVector2f second)
{
    sfVector2f diff;

    diff.x = first.x - second.x;
    diff.y = first.y - second.y;
    return (diff);
}

sfVector2f vect_add(sfVector2f first, sfVector2f second)
{
    sfVector2f add;

    add.x = first.x + second.x;
    add.y = first.y + second.y;
    return (add);
}