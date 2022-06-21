/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c by Elliot WALDVOGEL
** File description:
** my_compute_square_root
*/

int my_compute_square_root(int nb)
{
    int count = 0;

    if (nb <= 0)
        return (0);
    else if (nb == 1)
        return (1);
    else if (nb > 1) {
        for (int i = 2; count <= nb; i++) {
            if ((i*i) == nb)
                return (i);
            else if (i > nb)
                return (0);
            else
                count++;
        }
    }
}