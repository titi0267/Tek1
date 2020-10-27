/*
** EPITECH PROJECT, 2020
** Cpool day 4
** File description:
** gfs
*/

void swirch(int *f, int *l)
{
    int empty = *l;
    *l = *f;
    *f = empty;
}

int check_if_ordered(int *array, int size)
{
    int police = 0;

    for (int i = 0; i < size - 1; i++) {
        if (*(array + i) <= *(array + i + 1)) {
            police++;
        }
    }
    police++;
    if (police == size) {
        return (1);
    } else {
        return (0);
    }
}

void my_sort_int_array(int *array, int size)
{
    int cursor = 0;

    while (!check_if_ordered(array, size)) {
        if (cursor == (size - 1)) {
            cursor = 0;
        }
        if (*(array + cursor) > *(array + cursor + 1)) {
            swirch((array + cursor), (array + cursor + 1));
        }
        cursor++;
    }
}