/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday05-timothe.coniel
** File description:
** my_compute_factorial_it
*/

int my_compute_factorial_it(int nb)
{
    int end_nb = 1;
    int b = 1;

    if (nb == 1 || nb == 0) {
        return (1);
    } else if (nb < 0 || nb >= 13) {
        return (0);
    } else {
        while (end_nb != nb + 1) {
            b = b * end_nb;
            end_nb++;
        }
    }
    return (nb);
}

int main(void)
{

}