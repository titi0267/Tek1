/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-rush2-lilou.stoll-metz
** File description:
** frequencies
*/

int is_alpha(char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

float find_frequency(char *str, char c)
{
    int count_c = 0;
    int length = 0;
    char c2;

    if (c >= 'A' && c <= 'Z')
        c2 = c + 32;
    else if (c >= 'a' && c <= 'z')
        c2 = c - 32;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c || str[i] == c2)
            count_c += 1;
        if (is_alpha(str[i]) == 1)
            length += 1;
    }
    return ((float)count_c * 100 / (float)length);
}