/*
** EPITECH PROJECT, 2020
** my_print_revalpha
** File description:
** 
*/

int my_print_revalpha(void)
{
    char letter = 122;

    while(letter >=97){
        my_putchar(letter);
        letter--;
    }
    return(0);
}
