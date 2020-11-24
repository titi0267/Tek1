/*
** EPITECH PROJECT, 2020
** libmy
** File description:
** Declares macros from libmy
*/

#pragma once

// ONLY USE THIS MACRO WITH ARRAYS, NEVER WITH POINTERS
#define MY_COUNTOF(array) ((sizeof(array)) / (sizeof((array)[0])))

#define MY_MAX(a, b) ((a) > (b) ? (a) : (b))
#define MY_MIN(a, b) ((a) > (b) ? (b) : (a))
