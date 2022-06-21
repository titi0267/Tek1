/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares assert-related entities from libmy
*/

#pragma once

#include "config.h"
#include <stdbool.h>

void my_assert_fail(const char *expression, const char *file_name,
    int line_number, const char *function_name) MY_ATTR_NORETURN
    MY_ATTR_NOTHROW;

#define MY_ASSERT(expression)                           \
    ((bool)(expression) ? (void)0 :                     \
        my_assert_fail(#expression, __FILE__, __LINE__, \
        MY_PRETTY_FUNCTION))
