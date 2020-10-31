/*
** EPITECH PROJECT, 2020
** fff
** File description:
** ff
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