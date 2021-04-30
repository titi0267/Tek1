/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my
*/

#ifndef my
#define my

typedef struct stumper_s
{
    char *buffer;
    int buffer_size;
    int line_nbr;
    int char_nbr;
    char **line;
} stumper_t;

int error_core(int ac, char **av, stumper_t *stp);
int read_map(stumper_t *stp, char **av);
int store_map(stumper_t *stp);
int char_line(char *buff);
int nbr_line(char *buff);
int my_getnbr(char *buff);
void my_putchar(char c);
int my_putstr(char const *buff);

#endif /* !my */
