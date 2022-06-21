/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares bigint-related functions
*/

#pragma once

#include "config.h"
#include "my_string.h"
#include <unistd.h>
#include <stdbool.h>

// The number is stored as an array of char, with a value of 0 to 9 (integer,
// not characters)
struct my_bigint {
    struct my_string *number;
    bool is_negative;
};

// Creates a new bigint, based on the contents of the passed integer
struct my_bigint *my_bigint_new_from_int(int x) MY_ATTR_WARN_UNUSED_RESULT;

// Creates a new bigint, based on the contents of the passed string, which must
// be in the passed base. This differs from the standard strtol in that there
// may not be space or signs before the number, and it does not set errno
struct my_bigint *my_bigint_strtol_base_str(const char *num_ptr,
    char **end_num_ptr, const char *base) MY_ATTR_WARN_UNUSED_RESULT;

// Copies source into destination
struct my_bigint *my_bigint_assign(struct my_bigint *destination,
    const struct my_bigint *source);

// result += operand2
struct my_bigint *my_bigint_add(struct my_bigint *result,
    const struct my_bigint *operand2);

// Same as above, except operand2 is an int
struct my_bigint *my_bigint_add_int(struct my_bigint *result, int operand2);

// Same as above, but does not handle signs
struct my_bigint *my_bigint_add_unsigned(struct my_bigint *result,
    const struct my_bigint *operand2);

// result -= operand2
struct my_bigint *my_bigint_sub(struct my_bigint *result,
    const struct my_bigint *operand2);

// Same as above, except operand2 is an int
struct my_bigint *my_bigint_sub_int(struct my_bigint *result, int operand2);

// Same as above, but does not handle signs
struct my_bigint *my_bigint_sub_unsigned(struct my_bigint *result,
    const struct my_bigint *operand2);

// result *= operand2
struct my_bigint *my_bigint_mul(struct my_bigint *result,
    const struct my_bigint *operand2);

// Same as above, except operand2 is an int
struct my_bigint *my_bigint_mul_int(struct my_bigint *result, int operand2);

// result /= operand2
struct my_bigint *my_bigint_div(struct my_bigint *result,
    const struct my_bigint *operand2);

// Same as above, except operand2 is an int
struct my_bigint *my_bigint_div_int(struct my_bigint *result, int operand2);

// result %= operand2
struct my_bigint *my_bigint_mod(struct my_bigint *result,
    const struct my_bigint *operand2);

// Same as above, except operand2 is an int
struct my_bigint *my_bigint_mod_int(struct my_bigint *result, int operand2);

// self = -self
struct my_bigint *my_bigint_neg(struct my_bigint *self);

// Returns either -1 (operand1 < operand2), 0 (operand1 == operand2)
// or 1 (operand1 > operand2)
int my_bigint_compare(const struct my_bigint *operand1,
    const struct my_bigint *operand2) MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE;

// Same as above, except operand2 is an int
int my_bigint_compare_int(const struct my_bigint *operand1,
    int operand2) MY_ATTR_WARN_UNUSED_RESULT;

// Same as above, but does not handle signs
int my_bigint_compare_unsigned(const struct my_bigint *operand1,
    const struct my_bigint *operand2) MY_ATTR_WARN_UNUSED_RESULT MY_ATTR_PURE;

// Converts a bigint to a string of arbitrary base. Trashes the value in num
struct my_string *my_bigint_to_string_base(struct my_bigint *num,
    const char *base) MY_ATTR_WARN_UNUSED_RESULT;

// Converts a bigint to an int
int my_bigint_to_int(const struct my_bigint *num) MY_ATTR_WARN_UNUSED_RESULT
    MY_ATTR_PURE;

// Destructs the passed bigint and the associated data.
void my_bigint_free(struct my_bigint *num);
