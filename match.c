/*
** EPITECH PROJECT, 2020
** match -nmatch
** File description:
** match
*/

int match(char const *s1, char const *s2)
{
    int a = 0;
    int b = 0;

    while (s1[a] != '\0') {
        if (s1[a] == s2[b]) {
            a ++;
            b ++;
        }
        else if (s1[a] != s2[b] && s2[b] == '*') {
            while (s2[b + 1] == '*')
                b ++;
            while (s1[a] != s2[b + 1] && s1[a] != '\0')
                a ++;
            if (s1[a] == s2[b + 1])
                b ++;
        } else
            return (0);
    }
    if (s1[a] == s2[b])
        return (1);
}