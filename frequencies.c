/*
** EPITECH PROJECT, 2020
** B-CPE-100-STG-1-1-rush2-lilou.stoll-metz
** File description:
** frequencies
*/

int is_alpha (char c)
{
    if (c >= 'A' && c <= 'Z')
        return (1);
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

char *calc_frequency(int length, int count_c)
{
    int freq_int = count_c * 100 / length;
    int freq_float = count_c * 100 % length;
    freq_float = freq_float * 100 / length;
    char freq [7];

    freq[0] = (freq_int / 10) + 48;
    freq[1] = (freq_int % 10) + 48;
    freq[2] = '.';
    freq[3] = (freq_float / 10) + 48;
    freq[4] = (freq_float % 10) + 48;
    freq[5] = '%';
    freq[6] = '\0';
    return (freq);
}

char *find_frequency(char *str, char c)
{
    int count_c = 0;
    int length = 0;
    char c2;

    if (c >= 'A' && c <= 'Z')
        c2 = c + 32;
    else if (c >= 'a' && c <= 'z')
        c2 = c - 32;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c || str[i] == c2)
            count_c += 1;
        if (is_alpha(str[i]) == 1)
            length += 1;
    }
    calc_frequency(length, count_c);
    return (freq);
}