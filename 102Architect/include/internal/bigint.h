/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares internal bigint functions
*/

#include "my/bigint.h"

// Makes sure that num has at least the required amount of digits in it
// (reallocates if needed)
void my_bigint_at_least_digits(struct my_bigint *num, size_t required_digits);

// Computes both division and remainder at the same time, quotient
// must be a bigint with a value of 0 and remainder must be initialized
void my_bigint_div_mod(const struct my_bigint *num,
    const struct my_bigint *divisor, struct my_bigint *quotient,
    struct my_bigint *remainder);
