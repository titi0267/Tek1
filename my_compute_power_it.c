/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday05-timothe.coniel
** File description:
** my_compute_power_it
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;
    int a = 1;

    if (p == 0)
        result = 1;
    else if (p < 0) {
        result = 0;
    } else {
        while (p != a) {
            result = result * nb;
            a ++;
        }     
    }
    return (result);
}
