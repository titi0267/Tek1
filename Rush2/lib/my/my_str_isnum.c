/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_str_isnum
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 48 || str[i] > 57)
            return (0);
    }
    return (1);
}