    /*
** EPITECH PROJECT, 2021
** print resolved maze
** File description:
** print_path.c
*/

#include "include/solve.h"

void car_zero(read_t *rd)
{
    if (rd->car == 0 && rd->ln != 0 && rd->ln != rd->line_nbr - 1) {
        if (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            my_printf("YEE\n");
            exit (0);
            rd->car++;
        } else if (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] &&
            rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->line++;
        } else if (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
        }
    } else if (rd->car == 0 && rd->ln == 0) {
        if (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            rd->car++;
        } else if (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->line++;
        }
    }
}

void line_zero(read_t *rd)
{
    if (rd->ln == 0 && rd->car != 0 && rd->car != rd->char_nbr - 1) {
        if (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] &&
            rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->line++;
        } else if (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
        } else if (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1]  && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
    } else if (rd->ln == 0 && rd->car == rd->char_nbr - 1) {
        if (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->line++;
        } else if (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln][rd->car - 1] = 'o';
            rd->car--;
        }
    }
}

void last_car(read_t *rd)
{
    if (rd->car == rd->char_nbr - 1 && rd->ln != 0 && rd->ln != rd->line_nbr - 1) {
        if (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] &&
            rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->line++;
            } else if (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            } else if (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] &&
            rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
    } else if (rd->car == rd->char_nbr - 1 && rd->ln == rd->line_nbr - 1) {
        //my_printf("rd->ln = %c & rd->car == %i", rd->path[rd->ln][rd->car], car);
        if (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln][rd->car - 1] = 'o';
            my_printf("rd->car-- = %i\n", rd->car);
            rd->car--;
            my_printf("rd->car-- = %i\n", rd->car);
        } else if (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln - 1][rd->car] = 'o';
            rd->ln--;
        }
    } else if (rd->car != rd->char_nbr - 1 && rd->car != 0 && rd->ln == rd->line_nbr - 1) {
        my_printf("here\n");
        if (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln][rd->car - 1] = 'o';
            rd->car--;
        } else if (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && (rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            my_printf("ln = %i & car = %i\n", rd->ln, rd->car);
            rd->line[rd->ln - 1][rd->car] = 'o';
            rd->ln--;
        }
    }
}

/*void replace_solve(read_t *rd)
{
    rd->ln = rd->line_nbr - 1;
    rd->car = rd->char_nbr - 1;
    int edge = 0;

    while (rd->ln != 0 && rd->car != 0) {
        for (int i = 0; rd->line[i] != NULL; i++) {
            for (int d = 0; rd->line[i][d] != '\0'; d++) {
            //if (slv->rd->line[i][d] == '*')
            //    my_printf("%i", slv->rd->path[i][d]);
            //else
                my_printf("%c", rd->line[i][d]);
            }
        }
        if (rd->ln == 0 || rd->ln == rd->line_nbr - 1 || rd->car == 0 || rd->car == rd->char_nbr - 1) {
            car_zero(rd);
            line_zero(rd);
            //last_line(rd, line, car);
            last_car(rd);
            my_printf("edge\n");
            edge = 1;
        }
        if (edge == 0 && rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] &&
            rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && (rd->path[rd->ln][rd->car + 1] != -1 && rd->path[rd->ln - 1][rd->car] != -1 && rd->path[rd->ln + 1][rd->car] != -1 && rd->path[rd->ln][rd->car - 1] != -1)) {
            my_printf("gauche");
            rd->line[rd->ln][rd->car - 1] = 'o';
            rd->car--;
        } else if (edge == 0 &&
            rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] &&
            rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            rd->car++;
        } else if (edge == 0 &&
            rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && (rd->path[rd->ln][rd->car + 1] != -1 || rd->path[rd->ln - 1][rd->car] != -1 || rd->path[rd->ln + 1][rd->car] != -1 || rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->line++;
        } else {
            if (edge == 0) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
        }
        edge = 0;
    }

}*/

void replace_solve(read_t *rd)
{
    rd->ln = rd->line_nbr - 1;
    rd->car = rd->char_nbr - 1;
    my_printf("car = %i & line = %i\n", rd->ln, rd->car);
    while (rd->ln != 0 && rd->car != 0)
    {
    for (int i = 0; rd->line[i] != NULL; i++) {
        for (int d = 0; rd->line[i][d] != '\0'; d++) {
                my_printf("%c", rd->line[i][d]);
        }
    }
        if ((rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) && (rd->car != 0 && rd->car < (rd->char_nbr - 1))) {
            if (rd->path[rd->ln - 1][rd->car] != -1) {
                if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
                && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
                && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                    rd->line[rd->ln - 1][rd->car] = 'o';
                    rd->line--;
                }
            } else if (rd->path[rd->ln + 1][rd->car] != -1) {
                if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
                && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
                && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                    rd->line[rd->ln + 1][rd->car] = 'o';
                    rd->line++;
                }
            } else if (rd->path[rd->ln][rd->car - 1] != -1) {
                if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
                && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)
                && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                    rd->line[rd->ln][rd->car - 1] = 'o';
                    rd->car--;
                }
            } else if (rd->path[rd->ln][rd->car + 1] != -1) {
                if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
                && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)
                && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                    rd->line[rd->ln][rd->car + 1] = 'o';
                    rd->car++;
                }
            }
        }
    
    if (rd->ln == 0 && rd->car != 0 && rd->car < (rd->char_nbr - 1)) {
        if (rd->path[rd->ln + 1][rd->car] != -1) {
            if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            }
        } else if (rd->path[rd->ln][rd->car - 1] != -1) {
            if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
        } else if (rd->path[rd->ln][rd->car + 1] != -1) {
            if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        }
    } else if (rd->ln == 0 && rd->car == 0) {
        //A1 *1;
        if (rd->path[rd->ln][rd->car + 1] != -1 &&
        (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            rd->car++;
        } else if (rd->path[rd->ln + 1][rd->car] != -1 &&
        (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->ln++;
        }
    } else if (rd->ln == 0 && rd->car == (rd->char_nbr - 1)) {
       // A4 *1;
        if (rd->path[rd->ln][rd->car - 1] != -1 &&
        (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car - 1] = 'o';
            rd->car--;
        } else if (rd->path[rd->ln + 1][rd->car] != -1 &&
        (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln + 1][rd->car] = 'o';
            rd->ln++;
        }
    }
    if (rd->ln == (rd->line_nbr - 1) && rd->car != 0 && rd->car < (rd->char_nbr - 1)) {
        //C2 C3 *2;
        if (rd->path[rd->ln - 1][rd->car] != -1) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
        } else if (rd->path[rd->ln][rd->car - 1] != -1) {
            if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
        } else if (rd->path[rd->ln][rd->car + 1] != -1) {
            if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        }
    } else if (rd->ln == (rd->line_nbr - 1) && rd->car == 0) {
        //C1 *1;
        if (rd->path[rd->ln][rd->car + 1] != -1 &&
        (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car + 1] = 'o';
            rd->car++;
        } else if (rd->path[rd->ln - 1][rd->car] != -1 &&
        (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)) {
            rd->line[rd->ln - 1][rd->car] = 'o';
            rd->ln--;
        }
    } else if (rd->ln == (rd->line_nbr - 1) && rd->car == (rd->char_nbr - 1)) {
       // C4 *1;
        if (rd->path[rd->ln][rd->car - 1] != -1 &&
        (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
            rd->line[rd->ln][rd->car - 1] = 'o';
            rd->car--;
        } else if (rd->path[rd->ln - 1][rd->car] != -1 &&
        (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)) {
            rd->line[rd->ln - 1][rd->car] = 'o';
            rd->ln--;
        }
    }
    if (rd->car == 0 && rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) {
        //B1 * 1;
        if (rd->path[rd->ln - 1][rd->car] != -1) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
        } else if (rd->path[rd->ln + 1][rd->car] != -1) {
            if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car + 1] && rd->path[rd->ln][rd->car + 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            }
        } else if (rd->path[rd->ln][rd->car + 1] != -1) {
            if ((rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)
            && (rd->path[rd->ln][rd->car + 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car + 1] = 'o';
                rd->car++;
            }
        }


    }
    if (rd->car == (rd->char_nbr - 1) && rd->ln != 0 && rd->ln < (rd->line_nbr - 1)) {
        //B4 *1;
        if (rd->path[rd->ln - 1][rd->car] != -1) {
            if ((rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln - 1][rd->car] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)) {
                my_printf("l 308\n");
                rd->line[rd->ln - 1][rd->car] = 'o';
                rd->ln--;
            }
        } else if (rd->path[rd->ln + 1][rd->car] != -1) {
            if ((rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln][rd->car - 1] && rd->path[rd->ln][rd->car - 1] != -1)
            && (rd->path[rd->ln + 1][rd->car] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln + 1][rd->car] = 'o';
                rd->ln++;
            }
        } else if (rd->path[rd->ln][rd->car - 1] != -1) {
            if ((rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln + 1][rd->car] && rd->path[rd->ln + 1][rd->car] != -1)
            && (rd->path[rd->ln][rd->car - 1] <= rd->path[rd->ln - 1][rd->car] && rd->path[rd->ln - 1][rd->car] != -1)) {
                rd->line[rd->ln][rd->car - 1] = 'o';
                rd->car--;
            }
        }

    }
    }
}