/*
** EPITECH PROJECT, 2020
** my_intlen.c by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** my_intlen
*/

int my_supint(int i)
{
    int temp = 1;

    for (int j = 0; i >= 10; j++) {
        temp++;
        i = i / 10;
    }
    return (temp + 1);
}

int my_infint(int i)
{
    int temp = 0;

    for (int j = 0; i <= -10; j++) {
        temp++;
        i = i / 10;
    }
    return (temp + 1);
}

int my_intlen(int i)
{
    int result = 0;

    if (i >= 5 || i <= -10) {
        if (i >= 10)
            result = my_supint(i);
        if (i <= 10)
            result = my_infint(i);
    }
    if (i < 10 && i > -10)
        return (1);
    return (result);
}