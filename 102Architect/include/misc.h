/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares miscellaneous functions from libmy
*/

#pragma once

#include "config.h"
#include <stddef.h>
#include <stdbool.h>

bool my_putnbr(int number);
bool my_putnbr_base(int number, const char *base);
bool my_putnbr_base_width(int number, const char *base, size_t width);
char *my_nbr_to_string(int number) MY_ATTR_WARN_UNUSED_RESULT;
char *my_nbr_to_string_base(int number,
    const char *base) MY_ATTR_WARN_UNUSED_RESULT;
char *my_nbr_to_string_base_width(int number, const char *base,
    size_t width) MY_ATTR_WARN_UNUSED_RESULT;
int my_compute_power_rec(int number, int power) MY_ATTR_WARN_UNUSED_RESULT;
int my_compute_square_root(int number) MY_ATTR_WARN_UNUSED_RESULT;
bool my_is_prime(unsigned number) MY_ATTR_WARN_UNUSED_RESULT;
int my_find_prime_sup(int number) MY_ATTR_WARN_UNUSED_RESULT;
char *my_revstr(char *string);
char *my_strupcase(char *string);
char *my_strlowcase(char *string);
char *my_strcapitalize(char *string);
bool my_str_isalpha(const char *string) MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_PURE;
bool my_str_isnum(const char *string) MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE;
bool my_str_islower(const char *string) MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_PURE;
bool my_str_isupper(const char *string) MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_PURE;
bool my_str_isprintable(const char *string) MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_PURE;
size_t my_count_byte_occurences(const char *first, const char *last,
    char character) MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE;
bool my_show_word_array(char *const *table) MY_ATTR_WARN_UNUSED_RESULT;
char **my_str_to_word_array(const char *string) MY_ATTR_WARN_UNUSED_RESULT;
