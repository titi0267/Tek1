/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Displays a number in a given base and width
*/

#include "../../include/misc.h"
#include "../../include/my.h"
#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

static const int WORK_BUFFER_SIZE = 1000;

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
    const char *buffer_end, size_t width, infin_number_t *info)
{
    size_t converted_number_size = (size_t)(buffer_end - converted_number_ptr);

    info->amount += my_strlen(converted_number_ptr);
    if (converted_number_size > width)
        width = converted_number_size;
    while ((width--) > converted_number_size)
        if (my_putchari('0') == EOF)
            return (false);
    if ((size_t)write(STDOUT_FILENO, converted_number_ptr,
            converted_number_size) != converted_number_size)
        return (false);
    return (true);
}

int my_putnbr_base_width(int number, const char *base, size_t width,
infin_number_t *info)
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
    return (finish_conversion(converted_number_ptr, buffer_end, width, info));
}
