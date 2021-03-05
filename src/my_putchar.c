/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** 
*/

int my_putchar(char c)
{
    write(1, &c, 1);
    return (0);
}
