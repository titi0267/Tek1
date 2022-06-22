/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares checked_multiply-related functions from libmy
*/

#pragma once

#include "config.h"
#include <stdbool.h>

bool my_checked_multiply_int(int lhs, int rhs,
    int *result) MY_ATTR_WARN_UNUSED_RESULT;
bool my_checked_multiply_unsigned(unsigned lhs, unsigned rhs,
    unsigned *result) MY_ATTR_WARN_UNUSED_RESULT;
