/*
** EPITECH PROJECT, 2021
** generator main
** File description:
** generator.c
*/

#include "include/dante.h"

void empty_maze(char **av, pos_t *maze)
{
    maze->x = my_getnbr(av[1]);
    maze->y = my_getnbr(av[2]);
    int d = 0;
    int i = 0;

    //if ((maze = malloc(sizeof(pos_t))) == NULL) exit(84);
    if ((maze->maze = malloc(sizeof(char *) * (maze->x + 1))) == NULL) exit(84);
    for (; i < maze->x; i++) {
        maze->maze[i] = malloc(sizeof(char) * maze->y + 1);
        for (; d < maze->y; d++)
            maze->maze[i][d] = '*';
        /*
        maze->maze[i][d] = '\n';
        maze->maze[i][d + 1] = '\0';
        d = 0;
        */
        maze->maze[i][d] = '\0';
        d = 0;
    }
    maze->maze[i] = NULL;
}

void push(pos_t **head, int x, int y)
{
    pos_t *new = malloc(sizeof(pos_t));

    new->line = x;
    new->car = y;
    new->next = (*head);
    new->prev = NULL;
    if ((*head) != NULL)
        (*head)->prev = new;
    (*head) = new;
}

void print_list(pos_t **head)
{
    pos_t *node = (*head);

    for (; node != NULL; node = node->next)
        printf("line = %d & car = %d\n", node->line, node->car);
}

void init_unvisit(pos_t *maze)
{
    if ((maze->visit = malloc(sizeof(int *) * (maze->x + 3))) == NULL) exit(84);
    if ((maze->visit[0] = malloc(sizeof(int) * (maze->y + 3))) == NULL)
        exit(84);
    for (int s = 0; s <= maze->y + 1; s++) {
        maze->visit[0][s] = visited;
        my_printf("%i & s = %i & y = %i\n", maze->visit[0][s], s, maze->y);
    }
    maze->visit[0][maze->y + 2] = -1;
    for (int d = 0; maze->visit[0][d] != -1; d++)
            my_printf("%i", maze->visit[0][d]);
        my_printf("\n");
    for (int i = 1; i <= maze->x; i++) {
        if ((maze->visit[i] = malloc(sizeof(int) * (maze->y + 3))) == NULL)
            exit(84);
        maze->visit[i][0] = visited;
        for (int d = 1; d <= maze->y; d++)
            maze->visit[i][d] = unvisited;
        maze->visit[i][maze->y + 1] = visited;
        maze->visit[i][maze->y + 2] = -1;
        my_printf("visit = %i\n", maze->visit[i][maze->y + 2]);
    }
    if ((maze->visit[maze->x + 1] = malloc(sizeof(int) * (maze->y + 3))) == NULL)
        exit(84);
    for (int s = 0; s <= maze->y + 1; s++)
        maze->visit[maze->x + 1][s] = visited;
    maze->visit[maze->x + 1][maze->y + 2] = -1;
    maze->visit[maze->x + 2] = NULL;
    my_printf("nbr = %i\n", maze->visit[0][maze->y + 1]);
}

int pop(pos_t **pos)
{
    pos_t *rm = (*pos);

    if (rm == NULL)
        return (0);
    rm = (*pos);
    (*pos) = (*pos)->next;
    free(rm);
    return (0);
}

int up_visit(pos_t *maze, int i, int d, pos_t *pos)
{
    if (maze->visit[i][d - 1] != unvisited && maze->visit[i][d + 1] != unvisited
        && maze->visit[i + 1][d] != unvisited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d);
        return (0);
    }
    pop(&pos);
}

int down_visit(pos_t *maze, int i, int d, pos_t *pos)
{
    if (maze->visit[i][d - 1] != unvisited && maze->visit[i][d + 1] != unvisited
        && maze->visit[i - 1][d] != unvisited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d);
        return (0);
    }
    pop(&pos);
}

int left_visit(pos_t *maze, int i, int d, pos_t *pos)
{
    if (maze->visit[i][d - 1] != unvisited && maze->visit[i + 1][d] != unvisited
        && maze->visit[i - 1][d] != unvisited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d);
        return (0);
    }
    pop(&pos);
}

int right_visit(pos_t *maze, int i, int d, pos_t *pos)
{
    if (maze->visit[i][d + 1] != unvisited && maze->visit[i - 1][d] != unvisited
        && maze->visit[i + 1][d] != unvisited) {
        maze->visit[i][d] = visited;
        push(&pos, i, d);
        return (0);
    }
    pop(&pos);
}

void check_visit(pos_t *maze, int i, int d)
{
    int r = rand() % 4;
    pos_t *pos = NULL;

    if (r == 0)
        up_visit(maze, i - 1, d, pos);
    else if (r == 1)
        down_visit(maze, i + 1, d, pos);
    else if (r == 2)
        left_visit(maze, i, d - 1, pos);
    else
        right_visit(maze, i, d + 1, pos);
}

void adjust_border(pos_t *maze, int i, int d)
{
    if (i == 0)
        i += 1;
    if (i == maze->x)
        i -= 1;
    if (d == 0)
        d += 1;
    if (d == maze->y)
        d -= 1;
    check_visit(maze, i, d);
}

void forward_maze(pos_t *maze)
{
    int i = 0;
    int d = 0;
    //for (int i = 0; maze->maze[i] != NULL; i++) {
    //    for (int d = 0; maze->maze[i][d] != '\0'; d++)
    adjust_border(maze, i, d);
    //}
}

void link_list(pos_t *maze)
{
    pos_t *pos = NULL;

    push(&pos, 1, 2);
    push(&pos, 3, 4);
    push(&pos, 5, 6);
    push(&pos, 7, 8);
    print_list(&pos);
    my_printf("\n");
    pop(&pos);
    print_list(&pos);
    push(&pos, 7, 8);
    my_printf("\n");
    print_list(&pos);
}

int main(int ac, char **av)
{
    pos_t *maze = malloc(sizeof(pos_t));

    srand(time(NULL));
    if (maze == NULL) exit(84);
    empty_maze(av, maze);
    init_unvisit(maze);
    for (int i = 0; maze->maze[i] != NULL; i++) {
        for (int d = 0; maze->maze[i][d] != '\0'; d++)
            my_printf("%c", maze->maze[i][d]);
        my_printf("\n");
    }
    for (int i = 0; maze->visit[i] != NULL; i++) {
        for (int d = 0; maze->visit[i][d] != -1; d++)
            my_printf("%i", maze->visit[i][d]);
        my_printf("\n");
    }
    link_list(maze);
    return (0);
}