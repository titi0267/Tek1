/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** 
*/
int my_strlen(char const *str);

 char *my_strcat(char *dest, char const *src)
 {
    int i = 0;
    int j;

    j = my_strlen(dest);
    for (i = 0; src[j] != '\0'; j += 1) {
        dest[i] = src[j];
        i += 1;
    }
    dest[i] = '\0';
    return (dest);
 }

int main(void)
{
    char *dest;
    char const *src;
    
    my_strcat(dest, src);
    return (0);
}