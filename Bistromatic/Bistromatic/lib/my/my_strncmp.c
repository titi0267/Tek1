/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_strncmp.c
*/

int my_strncmp(const char *sen1, const char *sen2, int n)
{
    char ch1;
    char ch2;

    if (n == 0)
        return (0);
    do {
        n--;
        ch1 = *sen1++;
        ch2 = *sen2++;
        if (ch2 == '\0')
            return (ch1 - ch2);
    } while (ch2 == ch1 && n > 0);
    return (ch1 - ch2);
}