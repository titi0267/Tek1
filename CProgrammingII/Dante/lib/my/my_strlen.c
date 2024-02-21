/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-infinadd-sylvian.burn
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}
