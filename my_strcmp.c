/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** 
*/

int my_strcmp(char *s1, char const *s2)
{
    int a;
    int res;

    for (a = 0; s1[a] == s2[a] && s1[a] != '\0' && s2[a] != '\0'; a += 1) {
        if (s1[a] < s2[a] || s1[a] > s2[a])
            res = 0;
    }
    if (s1[a] == s2[a])
        res = 1;
    return(res);
}