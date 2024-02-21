/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_strcmp
*/

int my_strcmp(char const *s1, char const *s2)
{
    for (int i = 0; s1[i] != '\0'; i += 1) {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    return (0);
}