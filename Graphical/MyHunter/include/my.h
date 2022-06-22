/*
** EPITECH PROJECT, 2020
** B-MUL-100-STG-1-1-myhunter-timothe.coniel
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

void birdrect_speed(duck_t *pos, float delta_time);
void init_duck(duck_t *pos);
void move_straight(sfRenderWindow *window, duck_t *pos);
void move_rect(duck_t *pos);
int click(sfRenderWindow *window, sfEvent *event, duck_t *pos);
void poll_event(sfRenderWindow *window, duck_t *pos);
void restart(sfRenderWindow *window, sfEvent *event, duck_t *pos);
void edge_window(sfRenderWindow *window, duck_t *pos);

#endif /* !MY_H_ */
