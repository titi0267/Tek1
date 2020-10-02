/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday05-timothe.coniel
** File description:
** my_compute_factorial_it_rev
*/

int  my_compute_factorial_rec(int nb)
{
    int result;
    int end_nb = 1;
    int b = 1;

    if (nb == 0) {
        return (1);
    } else if (nb < 0 || nb > 2147483648) {
        return (0);
    } else {
        result = nb * my_compute_factorial_rec(nb - 1);
    }
    return (result);
}