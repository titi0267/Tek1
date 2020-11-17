/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-BSQ-timothe.coniel
** File description:
** store_car
*/
#include "../include/my.h"
#include "../include/steps.h"


void max_dot_line(char *buff, buffer_size_t *info)
{
    info->w = 0;
    info->i = 0;
    info->btw_o = 0;
    info->line = 0;
    for (; buff[info->w] >= 48 && buff[info->w] <= 57; info->w++);
    info->i = info->w + 1;
    for (; buff[info->i] != '\0'; info->i++) {
        if (buff[info->i] == '.')
            info->btw_o++;
        if (buff[info->i] == 'o' || buff[info->i] == '\n') {
            if (info->btw_o > info->store_btw) {
                info->store_btw = info->btw_o;
                info->store_nbrbuf = info->i - info->store_btw;
                info->store_enddot = info->i;
            }
            info->btw_o = 0;
        }
    }
}

void dot_pos(char *buff, buffer_size_t *info)
{
    max_dot_line(buff, info);
    int f = 0;

    for (; buff[f] != '\n'; f++)
        info->carac_l++;
    info->after_n = info->store_nbrbuf + (info->carac_l + 1);
    info->before_n = info->store_nbrbuf - (info->carac_l + 1);
    info->after_end = info->store_nbrbuf + (info->carac_l + 1);
    info->before_end = info->store_nbrbuf - (info->carac_l + 1);

    info->i = info->after;
}

void find_dots(char *buff, buffer_size_t *info)
{
    max_dot_line(buff, info);
    dot_pos(buff, info);
    int i = info->after_n;
    int w = info->before_n;
    int c = 0;

    for (; buff[i] == '.' && i <= info->after_end; i++)
        c++;
    if (c == info->store_btw)
        info->isdot = i - info->store_btw;

    if (buff[info->i] == '.')
            info->btw_o++;
        if (buff[info->i] == 'o' || buff[info->i] == '\n') {
            if (info->btw_o > info->store_btw) {
                info->store_btw = info->btw_o;
                info->store_nbrbuf = info->i - info->store_btw;
                info->store_enddot = info->i;
            }
        //if (buff[i + 1] == '\n' || buff[i + 1] == 'o')
        //    info->after_end

}