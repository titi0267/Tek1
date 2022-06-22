/*
** EPITECH PROJECT, 2020
** my_strstr
** File description:
** my_strstr
*/
int get_my_strlen(char *str)
{
    int length = 0;

    while ( str[length] != '\0' )
    {
        length += 1;
    }
    return (length);
}

int get_my_find(char *str, char *to_find, int j)
{
    int a = 0;
    int length_find = get_my_strlen(to_find) - 1;

    while (str[j] == to_find[a] && a < length_find)
    {
        j += 1;
        a += 1;
    }
    if (a == length_find)
        return (1);
    else
        return (0);
}

char *my_strstr(char *str, char *to_find)
{
    int i = 0;
    int j = 0;
    int length = get_my_strlen(str) - 1;
    int retour;

    while (str[j] != '\0') {
        if (str[j] == to_find[0])
        {
            retour = get_my_find(str, to_find, j);
            if (retour == 1) {
                return (&str[j]);
            }
        }
        j += 1;
    }
    return ("\0");
}