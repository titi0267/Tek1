/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strupcase.c
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (*(str + i) != '\0') {
        if ((*(str + i) > 96) && (*(str + i) < 123))
            *(str + i) = *(str + i) - 32;
        i++;
    }
    return (str);
}
