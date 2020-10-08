/*
** EPITECH PROJECT, 2020
** concat_params
** File description:
** 
*/
int my_putstr(char const *str);

char *concat_params(int argc , char **argv)
{
    int i = 0;
    int x = 0;
    int j = 0;
    char *str;

    str = malloc(sizeof(char) * (argc + 1));
    for (i = 0; i < argc; i+= 1) {
        for (j = 0; argv[i][j] != '\0'; j += 1) {
            str[x] = argv[i][j];
            x = x + 1;
        }
        str[x] = '\n';
        j = 0;
        x++;
    }
    str[x - 1] = '\0';
    return (str);
}