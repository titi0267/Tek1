/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Displays a number in a given base and width
*/

#include "my/misc.h"
#include "my/stdio.h"
#include "my/string.h"
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static const int WORK_BUFFER_SIZE = 1000;

// Converts an unsigned number into a string at buffer_end, going backwards
static char *core_number_converter(unsigned number, char *buffer_end,
    const char *base, size_t base_len)
{
    do {
        *--buffer_end = base[number % base_len];
        number /= base_len;
    } while (number != 0);
    return (buffer_end);
}

static bool finish_conversion(const char *converted_number_ptr,
    const char *buffer_end, size_t width)
{
    size_t converted_number_size = (size_t)(buffer_end - converted_number_ptr);

    if (converted_number_size > width)
        width = converted_number_size;
    while ((width--) > converted_number_size)
        if (my_putchar('0') == EOF)
            return (false);
    if ((size_t)write(STDOUT_FILENO, converted_number_ptr,
            converted_number_size) != converted_number_size)
        return (false);
    return (true);
}

// We convert the number into a string at a work buffer (we prepend a '-' for
// negative numbers). We can then print the padding (since we can determine the
// length of the converted string and whether it will be long enough) before
// printing the converted string from the buffer. NOTE: The buffer is *not*
// null-terminated
// Note: The conversion to unsigned in the call of
// core_number_printer will deal with INT_MIN : On all standard implementations
// (since C2x which mandates 2's complement) it will be converted to INT_MAX + 1
// when converted to unsigned (the value of -INT_MIN (non-withstanding the
// non-representability of `-INT_MIN`))
// We don't do the negation when we're asked to print INT_MIN because that'd be
// UB, and with wrapping overflow it just ends up being INT_MIN again
bool my_putnbr_base_width(int number, const char *base, size_t width)
{
    char buffer[WORK_BUFFER_SIZE];
    char *buffer_end = (buffer + WORK_BUFFER_SIZE);
    char *converted_number_ptr;
    bool is_negative = (number < 0);

    if (is_negative && number != INT_MIN)
        number = -number;
    converted_number_ptr = core_number_converter(
        (unsigned)number, buffer_end, base, my_strlen(base));
    if (is_negative)
        *--converted_number_ptr = '-';
    return (finish_conversion(converted_number_ptr, buffer_end, width));
}
