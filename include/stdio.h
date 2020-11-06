/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares stdio-related functions from libmy
*/

#pragma once

#include "config.h"

void my_putchar(char c);
int my_dputc(int character, int fd);
int my_dputs(const char *string, int fd);
int my_puts(const char *string);
