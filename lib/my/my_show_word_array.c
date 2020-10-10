/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday08-lilou.stoll-metz
** File description:
** my_show_word_array
*/

int  my_show_word_array(char * const *tab)
{
    int i;
    int j;
    int k;

    for (i = 0; tab[i] != '\0'; i++) {
        for (j = 0; j < my_strlen(tab[i]); j++){
            my_putchar(tab[i][j]);
        }
        my_putchar('\n');
    }
    return (0);
}