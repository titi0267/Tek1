/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_strlowcase
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 65 && str[i] <= 90)
            str[i] += 32;
    }
    return (str);
}