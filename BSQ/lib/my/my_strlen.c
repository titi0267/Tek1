/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday04-timothe.coniel
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0') 
        carac = carac + 1;
    return (carac);
}