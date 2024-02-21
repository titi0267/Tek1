/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    int a = 0;
    int b;
    int res;

    for (; s1[a] == s2[b] && s1[a] != '\0' && s2[b] != '\0'; a += 1) {
        b +=1;
    }
    if (s1[a] < s2[b])
        res = 1;
    else if (s1[a] > s2[b])
        res = -1;
    else
        res = 0;
    return (res);
}