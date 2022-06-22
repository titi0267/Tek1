/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares internal macros for non-portable stuff like attributes
*/

#pragma once

#ifdef __GNUC__
    #define MY_ATTRIBUTE(attr) __attribute__(attr)
    #define MY_PRETTY_FUNCTION __extension__ __PRETTY_FUNCTION__
#else
    #define MY_ATTRIBUTE(attr)
    #define MY_PRETTY_FUNCTION __func__
#endif

#define MY_ATTR_WARN_UNUSED_RESULT MY_ATTRIBUTE((warn_unused_result))
#define MY_ATTR_CONST MY_ATTRIBUTE((const))
#define MY_ATTR_NOTHROW MY_ATTRIBUTE((nothrow))
#define MY_ATTR_NONNULL(parameters) MY_ATTRIBUTE((nonnull parameters))
#define MY_ATTR_ALLOC_SIZE(parameters) MY_ATTRIBUTE((alloc_size parameters))
#define MY_ATTR_PURE MY_ATTRIBUTE((pure))
#define MY_ATTR_MALLOC MY_ATTRIBUTE((malloc))
#define MY_ATTR_NORETURN MY_ATTRIBUTE((noreturn))
