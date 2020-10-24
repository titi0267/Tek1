/*
** EPITECH PROJECT, 2020
** rush3.c by Elliot WALDVOGEL
** File description:
** rush3
*/

#include <stdlib.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/my_struct.h"

int display_special(infin_number_t *info)
{
    if (info->length == 1 && info->height == 1) {
        my_putstr("[rush1-3] 1 1 || [rush1-4] 1 1 || [rush1-5] 1 1");
        return (0);
    }
    if (info->length > 1 && info->height == 1) {
        my_putstr("[rush1-3] ");
        my_put_nbr(info->length);
        my_putstr(" 1 || [rush1-4] ");
        my_put_nbr(info->length);
        my_putstr(" 1 || [rush1-5] ");
        my_put_nbr(info->length);
        my_putstr(" 1");
        return (0);
    }
    if (info->height > 1 && info->length == 1) {
        my_putstr("[rush1-3] 1 ");
        my_put_nbr(info->height);
        my_putstr(" || [rush1-4] 1 ");
        my_put_nbr(info->height);
        my_putstr(" || [rush1-5] 1 ");
        my_put_nbr(info->height);
        return (0);
    }
}

int display_result(infin_number_t *info)
{
    my_put_nbr(info->first);
    if (info->first == 3)
        info->str = "[rush1-1] ";
    if (info->second == 3)
        info->str = "[rush1-2] ";
    if (info->third == 3)
        info->str = "[rush1-3] ";
    if (info->fourth == 3)
        info->str = "[rush1-4] ";
    if (info->fifth == 3)
        info->str = "[rush1-5] ";
    if (info->third == info->fourth && info->fourth == info->fifth) {
        display_special(info);
        return (0);
    }
    my_putstr(info->str);
    my_put_nbr(info->length);
    my_putchar(' ');
    my_put_nbr(info->height);
    return (0);
}

void detectOthers(infin_number_t *info, char *buff)
{
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '\n' && info->temp == 0) {
            detectSecondChar(buff[i - 1], info);
            info->length = i;
            info->temp = 1;
        }
        if (buff[i] == '\n')
            info->height++;
        if (buff[i] == '\0')
            detectLastChar(buff[i - 2], info);
    }
}

void rush3(char *buff)
{
    infin_number_t *info = malloc(sizeof(infin_number_t));
    info->temp = 0;
    info->height = 0;
    info->length = 0;
    info->first = 0;
    info->second = 0;
    info->third = 0;
    info->fourth = 0;
    info->fifth = 0;
    info->str1 = "ooo";
    info->str2 = "/\\/";
    info->str3 = "AAC";
    info->str4 = "ACC";
    info->str5 = "ACA";

    detectFirstChar(buff[0], info);
    detectOthers(info, buff);
    display_result(info);
    my_put_nbr(info->length);
    my_put_nbr(info->height);
}

int main(int ac, char **av)
{
    int buff_size = 2147483647;
    char *buff = malloc(sizeof(char) * buff_size);
    int offset = 0;
    int len;
    while ((len = read(0, buff + offset, buff_size - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
         return (84);
    rush3(buff);
    my_putchar('\n');
    return (0);
}