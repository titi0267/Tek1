unsigned/*
** EPITECH PROJECT, 2020
** task05
** File description:
** get number
*/

int my_getnbr(char const *str)
{
    int result = 0;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if ('0' <= str[i] && str[i] <= '9') {
            result += str[i] - 48;
            result *= 10;
        }
        if (str[i] == '-') {
            sign *= -1;
        }
    }
    result *= sign;
    result /= 10;
    return (result);
}