/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** store_car
*/
#include "../include/my.h"
#include "../include/steps.h"

void carac_on_line(char *buff, buffer_size_t *info) //this count the number of char on a line and the number of char on 'number line'
{
    info->carac_l = 0;
    info->nbr = 0;
    int line_char = 0;
    int carac = 1;

    for (; buff[info->nbr] >= 48 && buff[info->nbr] <= 57; info->nbr++);
    info->nbr = info->nbr + 1;
    //my_put_nbr(info->nbr);
    for (line_char = info->nbr; buff[line_char] != '\n'; line_char++)
        carac++;
    info->carac_l = carac;
}

/*void trans_char(char *buff, int i, int f, buffer_size_t *info)
{
/*    int d = 1;
    char *nbr

    for (; f / d >= 10; d * 10);
    for (; d > 0; d / 10) {
         = (f / d) % 10 + 48;
    }
        //my_putchar((nb / d) % 10 + '0');



}*/

int biggest(char *buff, int i, buffer_size_t *info)
{
    int f = 0;
    //info->carac_l = 98;
    if (buff[i - info->carac_l] - '0' <= buff[i - 1] - '0' &&
        buff[i - info->carac_l] - '0' <= buff[i - info->carac_l - 1] - '0') {
        //my_putchar('C');
        return (1);
    } else if (buff[i - 1] - '0' <= buff[i - info->carac_l] - '0' &&
        buff[i - 1] - '0' <= buff[i - info->carac_l - 1] - '0') {
        //my_putchar('D');
        return (2);
    }  else if (buff[i - info->carac_l - 1] - '0' <= buff[i - 1] - '0' &&
        buff[i - info->carac_l - 1] - '0' <= buff[i - info->carac_l] - '0') {
        //my_putchar('I');
        return (3);
    }
    return (0);
}
void square(char *buff, buffer_size_t *info)
{
    int i = 0;
    int x = 1;
    int y = 0;
    //int o = 0;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == '.') {
            buff[i] = '1';
            //o++;
            //biggest(buff, i, info);
            //my_put_nbr(1);
        }
        if (buff[i] == 'o') {
            buff[i] = '0';
            //biggest(buff, info);
            //my_put_nbr(0);
        }
        if (buff[i] == '\n') {
            buff[i] = '\n';
            //my_putchar('\n');
        }
    }
    //my_put_nbr(o);
}

void calc(char *buff, int i, buffer_size_t *info)
{
    carac_on_line(buff, info);
    //my_put_nbr(info->carac_l);
    i = 0;
    int f = 0;
    int x = 0;
    square(buff, info);
    for (; buff[i] != '\0'; i++) {
        if (buff[i] == 1 + 48 && i > info->carac_l) {
            if (buff[i - 1] - '0' >= buff[i] - '0' && buff[i - info->carac_l] - '0' >= buff[i] - '0'
                && buff[i - info->carac_l - 1] - '0' >= buff[i] - '0') {
                x = biggest(buff, i, info);
                if (x == 1) {
                    f = buff[i - info->carac_l] - 48 + buff[i] - 48;
                    //trans_char(buff, f, info);
                    buff[i] = f + 48;
                } if (x == 2) {
                    f = buff[i - 1] - 48 + buff[i] - 48;
                    //trans_char(buff, f, info);
                    buff[i] = f + 48;
                } if (x == 3) {
                    f = buff[i - info->carac_l - 1] - 48 + buff[i] - 48;
                    //trans_char(buff, f, info);
                    buff[i] = f + 48;
                } if (x == 0) {
                    buff[i] = buff[i];
                    //my_putchar('\n');
                }
            }
        }
    }
}

void find_square(char *buff, buffer_size_t *info)
{
    int i = 0;
    calc(buff, i, info);
    info->big = 0;
    info->where = 0;
    for (; buff[i] != '\0'; i++) {
        if (buff[i] - 48 > info->big) {
            info->big = buff[i] - 48;
            info->where = i;
        }
    }
}