/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares stdlib-related functions from libmy
*/

#pragma once

#include "config.h"
#include <stddef.h>

void my_qsort(void *base, size_t num_elements, size_t element_size,
    int (*comparison_function)(const void *, const void *))
    MY_ATTR_NONNULL((1, 4));
void my_qsort_r(void *base, size_t num_elements, size_t element_size,
    int (*comparison_function)(const void *, const void *, void *),
    void *argument) MY_ATTR_NONNULL((1, 4));
void *my_realloc_size(void *ptr, size_t new_length, size_t original_length)
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_NOTHROW MY_ATTR_ALLOC_SIZE((2));
// This allows an arbitrary amount of signs before the number, and handles them
// appropriately, so this doesn't behave exactly identically to strtol. It also
// does not set errno
long my_strtol_base_str(const char *num_ptr, char **end_num_ptr,
    const char *base) MY_ATTR_NONNULL((1, 3)) MY_ATTR_NOTHROW;
