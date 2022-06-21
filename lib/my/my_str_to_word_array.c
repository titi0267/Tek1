/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday08-lilou.stoll-metz
** File description:
** my_str_to_word_array
*/
#include <stdlib.h>

int is_alphanum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    if (c >= 'A' && c <= 'Z')
        return (1);
    return (0);
}

void malloc_words(char const *str, char **dest, int count)
{
    int letter = 0;
    int i = 0;

    for (int j = 0; j < count; j++) {
        for (; is_alphanum(str[i]) == 0; i++);
        for (; is_alphanum(str[i]) == 1; i++)
            letter += 1;
        dest[j] = malloc(sizeof(char) * (letter + 1));
        letter = 0;
    }

}

int count_word(char const *str)
{
    int word = 0;
    int i;

    if (is_alphanum(str[0]) == 1)
        word += 1;
    for (i = 0; str[i] != '\0'; i++)
        if (is_alphanum(str[i]) == 0 && is_alphanum(str[i + 1]) == 1)
            word += 1;
    return (word);
}

char **my_str_to_word_array(char const *str)
{
    char **dest;
    int count = 0;
    int word = 0;
    int letter = 0;
    int i = 0;

    count = count_word(str);
    dest = malloc(sizeof(char *) * (count + 1));
    malloc_words(str, dest, count);
    for (int j = 0; j < count; j++) {
        letter = 0;
        for (; is_alphanum(str[i]) == 0; i++);
        for (; is_alphanum(str[i]) == 1; i++) {
            dest[j][letter] = str[i];
            letter += 1;
        }
        dest[j][letter] = '\0';
    }
    dest[count] = NULL;
    return (dest);
}