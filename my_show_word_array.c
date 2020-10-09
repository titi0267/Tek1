/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** my_show_word_array
*/
void my_putchar(char c);

int my_show_word_array(char * const *tab)
{
    int i;
    int x;

    for (i = 0; tab[i] != NULL; i++) {
        for (x = 0; tab[i][x] != '\0'; x +=1) {
            my_putchar(tab[i][x]);
        }
        x = 0;
        my_putchar('\n');
    }
    return (0);
}