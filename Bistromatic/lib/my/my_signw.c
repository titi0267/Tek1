/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** my_signw.c
*/

int sign_d(char *sign, int par)
{
    char c = sign[0];

    if (c == '+' || c == '-')
        return (1);
    else if (c == '*' || c == '/' || c == '%')
        return (2);
    if (par == 1) {
        if (c == '(' || c == ')')
            return (0);
    }

    return (0);
}

int sign_w(char s)
{
    switch (s) {
    case '+':
        return (1);
    case '-':
        return (2);
    case '*':
        return (3);
    case '/':
        return (4);
    case '%':
        return (5);
    default:
        break;
    }
    return (0);
}

int check_if_sign(char s, int *inf)
{
    if (sign_w(s) != 0) {
        *inf = 1;
        return (1);
    }
    *inf = 0;
    return (0);
}

