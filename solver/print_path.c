    /*
** EPITECH PROJECT, 2021
** print resolved maze
** File description:
** print_path.c
*/

#include "include/solve.h"

void car_zero(read_t *rd, int car, int line)
{
    if (car == 0 && line != 0 && line != rd->line_nbr) {
        if (rd->path[line][car + 1] <= rd->path[line + 1][car] &&
            rd->path[line][car + 1] <= rd->path[line - 1][car]) {
            rd->line[line][car + 1] = 'o';
            my_printf("YEE\n");
            exit (0);
            car++;
        } else if (rd->path[line + 1][car] <= rd->path[line - 1][car] &&
            rd->path[line + 1][car] <= rd->path[line][car + 1]) {
            rd->line[line + 1][car] = 'o';
            line++;
        } else if (rd->path[line - 1][car] <= rd->path[line + 1][car] &&
            rd->path[line - 1][car] <= rd->path[line][car + 1]) {
                rd->line[line - 1][car] = 'o';
                line--;
        }
    } else if (car == 0 && line == 0) {
        if (rd->path[line][car + 1] <= rd->path[line + 1][car]) {
            rd->line[line][car + 1] = 'o';
            car++;
        } else if (rd->path[line + 1][car] <= rd->path[line][car - 1]) {
            rd->line[line + 1][car] = 'o';
            line++;
        }
    }
}

void line_zero(read_t *rd, int line, int car)
{

}

void replace_solve(read_t *rd)
{
    int line = 0;
    int car = 0;
    int edge = 0;

    while (line != rd->line_nbr && car != rd->char_nbr) {
        if (line == 0 || line == rd->line_nbr || car == 0 || car == rd->char_nbr) {
            edge = 1;
        }
        if (edge == 0 && rd->path[line][car - 1] <= rd->path[line + 1][car] &&
            rd->path[line][car - 1] <= rd->path[line][car + 1] &&
            rd->path[line][car - 1] <= rd->path[line - 1][car]) {
            rd->line[line][car - 1] = 'o';
            car--;
        } else if (edge == 0 &&
            rd->path[line][car + 1] <= rd->path[line + 1][car] &&
            rd->path[line][car + 1] <= rd->path[line - 1][car]) {
            rd->line[line][car + 1] = 'o';
            car++;
        } else if (edge == 0 &&
            rd->path[line + 1][car] <= rd->path[line - 1][car]) {
            rd->line[line + 1][car] = 'o';
            line++;
        } else {
            if (edge == 0) {
                rd->line[line - 1][car] = 'o';
                line--;
            }
        }
        edge = 0;
    }

}
