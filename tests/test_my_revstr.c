/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** test_my_revstr
*/

#include  <criterion/criterion.h>

Test(my_revstr , copy_five_characters_in_empty_array)
{
    char  dest[] = "Hello";
    my_revstr(dest);
    cr_assert(dest != "Hello");
}