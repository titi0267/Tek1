/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n; i += 1) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}