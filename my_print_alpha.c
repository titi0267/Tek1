/*
** EPITECH PROJECT, 2020
** my_print_alpha
** File description:
** 
*/

int my_print_alpha(void)
{
    char letter = 97;

    while(letter <= 122){
        my_putchar(letter);
        letter++;
    }
    return(0);
}
