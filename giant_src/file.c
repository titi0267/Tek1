/*
** EPITECH PROJECT, 2021
** file_giant.c for antman project by Timothy CONIEL & Elliot WALDVOGEL
** File description:
** file_giant
*/

#include "../include/my.h"
#include "../include/my_struct.h"
#include <stdio.h>

int cutting(giant_t *buffer)
{
    int i = 0;
    int j = buffer->keysize;
    int h = buffer->keysize + buffer->codesize + 1;

    for (; i < buffer->keysize; i++)
        buffer->key[i] = buffer->str[i];
    buffer->key[buffer->keysize] = '\0';
    i = 0;
    for (; j < buffer->keysize + buffer->codesize; j++, i++)
        buffer->code[i] = buffer->str[j + 1];
    buffer->code[buffer->codesize] = '\0';
    i = 0;
    for (; h < buffer->keysize + buffer->codesize + buffer->oversize + 1; h++
    , i++)
        buffer->leftover[i] = buffer->str[h + 1];
    buffer->leftover[buffer->oversize] = '\0';
    return (0);
}

int size_analysis(giant_t *buffer)
{
    buffer->keysize = 0;
    buffer->codesize = 0;
    buffer->oversize = 0;

    while (buffer->str[buffer->keysize] != '@')
        buffer->keysize++;
    if (buffer->str[buffer->keysize] == '@') {
        while (buffer->str[buffer->keysize + buffer->codesize + 1] != '@') {
            buffer->codesize++;
        }
    }
    if (buffer->str[buffer->keysize + buffer->codesize + 1] == '@') {
        while (buffer->str[buffer->keysize + buffer->codesize +
        buffer->oversize + 2] != '@')
            buffer->oversize++;
    }
    if (buffer->str[buffer->keysize + buffer->codesize +
    buffer->oversize + 2] == '@')
        return (0);
    //my_puterr("Giantman cannot work with this encoded file")
    return (84);
}

int read_map_next_giant(giant_t *buffer, int fd)
{
    ssize_t read_ret = 0;
    buffer->word = 0;

    read_ret = read(fd, buffer->str, buffer->buffer_size);
    if (read_ret == -1)
        my_printf("Couldn't read the buffer\n");
    return (read_ret);
}

int read_map_giant(giant_t *buffer, char *filepath)
{
    struct stat buff;
    ssize_t read_ret = 0;
    int fd = open(filepath, O_RDONLY);

    if (fd == -1 || stat(filepath, &buff) == -1) {
        my_printf("Couldn't open the file because of a wrong filepath\n");
        return (-1);
    }
    buffer->buffer_size = buff.st_size + 1;
    buffer->str = malloc(sizeof(char) * buffer->buffer_size);
    if (buffer->str == NULL) {
        my_printf("Malloc didn't worked as expected\n");
        return (-1);
    }
    read_ret = read_map_next_giant(buffer, fd);
    if (read_ret == -1)
        return (-1);
    buffer->str[buffer->buffer_size - 1] = '\0';
    close(fd);
    return (0);
}

int wich_map_giant(char **av, giant_t *buffer)
{
    if (read_map_giant(buffer, av[1]) == 0 && encoded_error(buffer) == 0
    && size_analysis(buffer) == 0) {
        buffer->key = malloc(sizeof(char) * buffer->keysize + 1);
        buffer->code = malloc(sizeof(char) * buffer->codesize + 1);
        buffer->leftover = malloc(sizeof(char) * buffer->oversize + 1);
        if (cutting(buffer) == 0) {
            //my_putchar('\n');
            my_printf("Hello\n");
            ascToBin(buffer);
            /*my_putstr(buffer->key);
            my_putchar('\n');
            my_putstr(buffer->code);
            my_putchar('\n');
            my_putstr(buffer->leftover);
            my_putchar('\n');*/
            return (0);
        }
    }
    return (84);
}
