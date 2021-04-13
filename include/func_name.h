/*
** EPITECH PROJECT, 2021
** include prototype
** File description:
** prototype.h
*/

#ifndef prototype
#define prototype

#include "rpg.h"

int first_alloc(rpg_t *rpg);
int basic_malloc(basic_t *basic);


void create_window(basic_t *basic);

void open_window(rpg_t *rpg);
void inside_open(rpg_t *rpg);
void event(rpg_t *rpg);
void get_mouse_pos(basic_t *basic);
void moove_clock(cloc_t *clk);




#endif /* !prototype */
