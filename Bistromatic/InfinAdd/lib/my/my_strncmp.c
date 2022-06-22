/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** my_strncmp
*/

int my_strncmp(char *s1, char const *s2, int n)
{
    int a;
    int b = 0;
    int res;

    for (a = 0; s1[a] == s2[b] && s1[a] && s2[b] != '\0' && a < n; a += 1) {
        b +=1;
    }
    if (s1[a] < s2[b])
        res = 1;
    if (s1[a] > s2[b])
        res = -1;
    else if (s1[a] == s2[b])
        res = 0;
    return(res);
}