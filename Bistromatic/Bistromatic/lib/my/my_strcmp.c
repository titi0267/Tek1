/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strcmp.c
*/

int my_strcmp(const char *sen1, const char *sen2)
{
    char ch1;
    char ch2;

    do {
        ch1 = *sen1++;
        ch2 = *sen2++;
        if (ch2 == '\0')
            return (ch1 - ch2);
    } while (ch2 == ch1);
    return (ch1 - ch2);
}