/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** 
*/

/*int my_strlen(char const *str)
{
    int carac = 0;

    while (str[carac] != '\0')
        carac = carac + 1;
    return (carac);
}

int my_strstr(char const *s1, char const *s2)
{
    int a = 0;
    int b = 0;
    int nb = my_strlen(s2);

    while (s1[a] != '\0' && s2[b] != '\0') {
        if (s1[a] == s2[b]) {
            a += 1;
            b += 1;
        }
        if (b == nb)
            return (0);
        else if (s1[a] > s2[b])
            return (1);
        else
            return (-1);
        }
}

char *my_strcmp(char *s1 , char  const *s2)
{
    int a = 0;
    int b = 0;
    int res = 0;

    for (; s1[a] != '\0'; a += 1) {
        if (s1[a] == s2[b]) {
            res = my_strstr(s1, s2);
        
        }
        if (res == 1) {
            return (1);
        else if (res == 0) {
        }
            return (0);
        }
        else {
            return (-1);
            printf("IN");
        }
    }
    return (res);
}

int main(void)
{
    char s1[] = "printf de la string interdit";
    char s2[] = "lolo";

    printf(my_strcmp(s1, s2));
}*/