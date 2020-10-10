/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday08-lilou.stoll-metz
** File description:
** my_strdup
*/

char *my_strdup(char  const *src) {
    char *str;
    int i;

    str = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (i = 0; i < my_strlen(src); i++) {
        str[i] = src[i];
    }
    str[i + 1] = '\0';
    return(str);
}