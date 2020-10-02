/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday04-timothe.coniel
** File description:
** my_getnbr
*/

void check_neg(char prev_char, int *neg)
{
    if (prev_char == '-')
        *neg = 1;
}

void check_still_nb(int prev_char, int act_char, int *still_nb)
{
    if (prev_char >= '0' && prev_char <= '9') {
        if (act_char < '0' || act_char > '9') {
            *still_nb = 0;
        }
    }
}

void test_validity(long *nb, int *final_nb, int neg)
{
    if (nb > 2147483647 && *neg == 0) {
        final_nb = 0;
    } else if (nb > 2147483648 && *neg == 1) {
        *final_nb = 0;
    } else {
        *final_nb = nb;
    }
    if (neg == 1 && *final_nb != 0) {
        *final_nb *= -1;
    }
}

int my_getnbr(char const *str)
{
    int neg = 0;
    long int nb = 0;
    int final_nb;
    int i = 0;
    int still_nb = 1;

    while (str[i] != '\0') {
        if (48 <= str[i] && str[i] <= 57 && still_nb == 1) {
            nb *= 10;
            nb += (str[i] - '0');
            check_neg(str[i-1], &neg);
        }
        check_still_nb(str[i - 1], str[i], &still_nb);
        i ++;
    }
    test_validity(&nb, &final_nb, &neg);
    return (final_nb);
}