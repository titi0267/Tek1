/*
** EPITECH PROJECT, 2021
** user input by Timothy CONIEL
** File description:
** recover user input
*/

#include "../include/matchstick.h"

int get_usr_line(user_t *user, map_t *map)
{
    int x = 0;
    size_t len = 0;

    while (1) {
        len = 0;
        user->str = NULL;
        my_printf("Line: ");
        if (getline(&user->str, &len, stdin) != -1) {
            user->error = FALSE;
            x = take_line_input(user, map);
            if (x == 0) {
                return (0);
            }
        } else
            return (2);
    }
    return (0);
}

int get_usr_match(user_t *user, map_t *map)
{
    size_t len = 0;
    int ret_input = 0;

    while (user->error == FALSE) {
        len = 0;
        user->str = NULL;
        my_printf("Matches: ");
        if (getline(&user->str, &len, stdin) != -1) {
            ret_input = take_match_input(user, map);
            if (ret_input == ERROR) {
                user->error = TRUE;
                return (4);
            }
            if (ret_input == 0)
                return (0);
        } else
            return (2);
    }
    return (0);
}

int user_turn(map_t *map, user_t *user)
{
    int x = 0;

    if (user->error == FALSE)
        my_printf("\nYour turn:\n");
    if (get_usr_line(user, map) == 2)
        return (1);
    if (user->error == FALSE)
        x = get_usr_match(user, map);
    if (x == 2)
        return (1);
    else if (x == 4)
        return (4);
    my_printf("Player removed %i match(es) from line %i\n",
            user->matches, user->line);
    remove_matches_usr(map, user);
    for (int i = 0; map->map[i] != NULL; i++)
        my_printf("%s", map->map[i]);
    is_pipe_user(map, user);
    return (0);
}

int main_loop(core_t *core)
{
    int x = 0;

    core->user->error = FALSE;
    while (1) {
        x = user_turn(core->map, core->user);
        if (x == 1)
            return (1);
        else if (x != 4) {
            if (core->user->lose == TRUE)
                break;
            core->user->error = FALSE;
            ai_turn(core->map, core->ai);
            if (core->ai->lose == TRUE)
                break;
        }
    }
    return (0);
}