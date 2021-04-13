    /*
** EPITECH PROJECT, 2021
** print resolved maze
** File description:
** print_path.c
*/

#include "include/solve.h"

void replace_solve(read_t *rd)
{
    rd->line[rd->ln][rd->car] = 'o';
    while (rd->ln != 0 || rd->car != 0) {
        if ((rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) && rd->car != 0 && rd->car < (rd->char_nbr - 1)) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            } else if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            } else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            } else if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        }
        if (rd->ln == 0 && rd->car != 0 && rd->car < (rd->char_nbr - 1)) {
            if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            } else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            } else if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        } else if (rd->ln == 0 && rd->car == 0) {
        if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            rd->car++;
        } else if (rd->path[rd->ln + 1][rd->car] != -1 &&
        (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->ln++;
        }
    } else if (rd->ln == 0 && rd->car == (rd->char_nbr - 1)) {
        if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car - 1] = 'o';
            rd->car--;
        } else if (rd->path[rd->ln + 1][rd->car] != -1 &&
        (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->ln++;
        }
    }
        if (rd->ln == (rd->line_nbr - 1) && rd->car != 0 && rd->car < (rd->char_nbr - 1)) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
            else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
            else if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        } else if (rd->ln == (rd->line_nbr - 1) && rd->car == 0) {
            if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            } else if (rd->path[rd->ln - 1][rd->car] != 1000000 &&
            (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
        } else if (rd->ln == (rd->line_nbr - 1) && rd->car == (rd->char_nbr - 1)) {
            if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            } else if (rd->path[rd->ln - 1][rd->car] != 1000000 &&
            (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
        }
        if (rd->car == 0 && rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
            else if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            }
            else if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        }
        if (rd->car == (rd->char_nbr - 1) && rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
            else if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            }
            else if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
        }
    }
}