/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday04-timothe.coniel
** File description:
** my_putstr
*/

int my_putstr(char const *str)
{
    char carac;

    carac = 0;
    while (str[carac] != '\0' ) 
    {
        my_putchar(str[carac]);
        carac++;
    }

}