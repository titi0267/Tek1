/*
** EPITECH PROJECT, 2021
** B-MUL-200-STG-2-1-mydefender-timothe.coniel
** File description:
** defender
*/

#ifndef DEFENDER_H_
#define DEFENDER_H_
#include  "../lib/my/my.h"
#include "struct.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <fcntl.h>
#include <stddef.h>

int start_error(int ac, char **av);

void initialize_wnd(window_t *wnd);
void wnd_open(core_t *core);

void destroy1(core_t *core);


#endif /* !DEFENDER_H_ */
