/*
** EPITECH PROJECT, 2020
** my_sort_int_array.c by Elliot WALDVOGEL
** File description:
** my_sort_int_array
*/

void my_sort_int_array(int *array, int size)
{
    int i = 0;
    int tmp = 0;

    while (i != size) {
        if (i > 0 && array[i] < array[i - 1]) {
            tmp = array[i];
            array[i] = array[i - 1];
            array[i - 1] = tmp;
            i -= 2;
        }
        i += 1;
    }
}
