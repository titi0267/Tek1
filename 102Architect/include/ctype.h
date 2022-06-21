/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares ctype-related functions from libmy
*/

#pragma once

#include "config.h"
#include <ctype.h>

int my_isprint(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_isupper(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_isalnum(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_isdigit(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_isalpha(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_isspace(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_islower(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_tolower(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
int my_toupper(int character)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_CONST MY_ATTR_NOTHROW;
