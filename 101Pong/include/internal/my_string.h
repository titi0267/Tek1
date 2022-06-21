/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares internal my_string-related functions
*/

#pragma once

#include "my/my_string.h"
#include <stddef.h>

// Guarantees that at least self->length + length + 1 bytes are allocated in
// self
struct my_string *my_string_guarantee_can_expand(struct my_string *self,
    size_t length);
