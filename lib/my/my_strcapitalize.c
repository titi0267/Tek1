/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-cpoolday06-lilou.stoll-metz
** File description:
** my_strcapitalize
*/

char *my_strcapitalize(char *str)
{
    int temp = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] >= 97 && str[i] <= 122 && temp == 0) {
            str[i] -= 32;
            temp = 1;
        }
        if (str[i] < 65 || 97 > str[i] > 90 || str[i] > 122) {
            temp = 0;
        }
    }
    return (str);
}