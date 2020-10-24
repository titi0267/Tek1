/*
** EPITECH PROJECT, 2020
** my_strncmp.c by Elliot WALDVOGEL
** File description:
** my_strncmp
*/

int compare_s1n(char const *s1, char const *s2, int n)
{
    int count = 0;

    for (int i = 0; (i < n) && (s1[i] != '\0'); i++) {
        if (s1[i] == s2[i])
            count += 0;
        else if (s1[i] > s2[i])
            count += 1;
        else
            count -= 1;
    }
    return (count);
}

int compare_s2n(char const *s1, char const *s2, int n)
{
    int count = 0;

    for (int i = 0; (i < n) && (s2[i] != '\0'); i++) {
        if (s1[i] == s2[i])
            count += 0;
        else if (s1[i] > s2[i])
            count += 1;
        else
            count -= 1;
    }
    return (count);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int count1 = 0;
    int length1 = my_strlen(s1);
    int length2 = my_strlen(s2);

    if (length1 > length2)
        return (compare_s1n(s1, s2, n));
    else if (length1 < length2)
        return (compare_s2n(s1, s2, n));
    else
        return (compare_s1n(s1, s2, n));
}