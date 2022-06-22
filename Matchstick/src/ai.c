/*
** EPITECH PROJECT, 2021
** ai by TImothy CONIEL
** File description:
** articficial intelligence against user
*/

#include "../include/matchstick.h"
#include <time.h>

int enough_matches_ai(ai_t *ai, map_t *map)
{
    int count_matches = 0;

    for (int i = 0; map->map[ai->line_chosen][i] != '\n'; i++) {
        if (map->map[ai->line_chosen][i] == '|')
            count_matches++;
    }
    return (count_matches);
}

int take_match_ai(ai_t *ai, map_t *map)
{
    if (ai->matches_to_rm == 0)
        return (ERROR);
    if (enough_matches_ai(ai, map) < ai->matches_to_rm)
        return (ERROR);
    return (0);
}

int ai_rand(ai_t *ai)
{
    ai->line_chosen = (rand() % (ai->line) + 1);
    ai->matches_to_rm = (rand() % (ai->matches) + 1);
    return (0);
}

void ai_choice(ai_t *ai, map_t *map)
{
    my_printf("\nAI's turn...\n");
    srand(time(NULL));
    while (1) {
        ai_rand(ai);
        if (take_match_ai(ai, map) == 0)
            break;
    }
    remove_matches_ai(map, ai);
    my_printf("AI removed %i match(es) from line %i\n",
                ai->matches_to_rm, ai->line_chosen);
}

void ai_turn(map_t *map, ai_t *ai)
{
    ai_choice(ai, map);
    for (int i = 0; map->map[i] != NULL; i++)
        my_printf("%s", map->map[i]);
    is_pipe_ai(map, ai);
}
