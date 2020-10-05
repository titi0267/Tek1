/*
** EPITECH PROJECT, 2020
** test_my_strncpy
** File description:
** 
*/

#include  <criterion/criterion.h>

Test(my_strncpy , reverse_caracters)
{
    char  dest [6] = {0};
    my_strncpy(dest , "HelloWorld", 5);
    cr_assert_str_eq(dest , "Hello");
}