/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday05-timothe.coniel
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    int result = nb;
    int a = 1;

    if (p == 0)
        result = 1;
    else if (p < 0) {
        result = 0;
    } else {
        result = nb * my_compute_power_rec(nb, p - 1);
    }     
    return (result);
}