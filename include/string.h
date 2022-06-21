/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares string-related functions from libmy
*/

#pragma once

#include "config.h"
#include <stddef.h>

size_t my_strlen(const char *string) MY_ATTR_NOTHROW MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_NONNULL((1)) MY_ATTR_PURE;
size_t my_strnlen(const char *string, size_t length) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1));
char *my_strcpy(char *destination, const char *source) MY_ATTR_NOTHROW
    MY_ATTR_NONNULL((1, 2));
char *my_strncpy(char *destination, const char *source, size_t n)
    MY_ATTR_NOTHROW MY_ATTR_NONNULL((1, 2));
char *my_strdup(const char *string) MY_ATTR_NOTHROW MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_MALLOC MY_ATTR_NONNULL((1));
char *my_strndup(const char *string, size_t length) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_MALLOC MY_ATTR_NONNULL((1));
char *my_strcat(char *destination, const char *source) MY_ATTR_NOTHROW
    MY_ATTR_NONNULL((1, 2));
char *my_strncat(char *destination, const char *source, size_t n)
    MY_ATTR_NOTHROW MY_ATTR_NONNULL((1, 2));
char *my_strchr(const char *str, int character) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1));
int my_strcmp(const char *string1, const char *string2) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1, 2));
int my_strncmp(const char *string1, const char *string2, size_t n)
    MY_ATTR_NOTHROW MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE
    MY_ATTR_NONNULL((1, 2));
char *my_strstr(const char *haystack, const char *needle) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1, 2));
size_t my_strspn(const char *str, const char *accept) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1, 2));
size_t my_strcspn(const char *str, const char *reject) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1, 2));
void *my_memcpy(void *destination, const void *source, size_t size)
    MY_ATTR_NOTHROW MY_ATTR_NONNULL((1, 2));
void *my_memmove(void *destination, const void *source, size_t size)
    MY_ATTR_NOTHROW MY_ATTR_NONNULL((1, 2));
void *my_memset(void *destination, int character, size_t length) MY_ATTR_NOTHROW
    MY_ATTR_NONNULL((1));
void *my_memchr(const void *ptr, int character, size_t length) MY_ATTR_NOTHROW
    MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE MY_ATTR_NONNULL((1));
