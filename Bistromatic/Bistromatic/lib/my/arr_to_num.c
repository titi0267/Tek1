/*
** EPITECH PROJECT, 2020
** B-CPE-101-STG-1-1-bistromatic-timothe.coniel
** File description:
** arr_to_num.c
*/

#include "include/my.h"
#include <stdio.h>
#include <stdlib.h>

int num_len(int num)
{
    int len = 0;

    if (num == 0)
        return (1);
    while (num != 0) {
        num = num / 10;
        len++;
    }
    return (len);
}

int arr_sum(int *arr)
{
    int sum = 0;

    for (int i = 0; arr[i] != -1; i++) {
        sum += arr[i];
    }
    return (sum);
}

int arr_to_num(int *arr_to_num)
{
    int to_bereturned = 0;

    for (int i = 0; arr_to_num[i] != 0; i++) {
        to_bereturned *= my_pow(10, num_len(arr_to_num[i]));
        to_bereturned += arr_to_num[i];
    }
    return (to_bereturned);
}