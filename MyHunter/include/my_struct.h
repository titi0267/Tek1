/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-timothe.coniel
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
#define MY_STRUCT_H_

typedef struct duck_s {
    sfIntRect rect;
    sfTexture *duck_straight;
    sfSprite *my_duck_straight;
    sfVector2f position;
    sfVector2f scale;
    int offset;
} duck_t;

#endif /* !MY_STRUCT_H_ */
