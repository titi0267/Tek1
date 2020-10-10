/*
** EPITECH PROJECT, 2020
** task 05
** File description:
** square root rec
*/

int my_compute_square_root(int nb)
{
    int square;

    if (nb <= 0)
        return (0);
    for (int compt = 1; compt <= nb; compt++)
    {
        square = compt * compt;
        if (square > nb)
            return (0);
        if (square == nb)
            return (compt);
    }
}