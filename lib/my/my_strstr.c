/*
** EPITECH PROJECT, 2020
** strstr
** File description:
** find a str
*/

char *my_strstr(char *str, char const *to_find)
{
    int n = my_strlen (to_find) - 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_strncmp(&str[i], to_find, n) == 0) {
            return (&str[i]);
        }
    }
    return (0);
}