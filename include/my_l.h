/*
** EPITECH PROJECT, 2020
** gg
** File description:
** gg
*/

#ifndef MY_L_H_
#define MY_L_H_
typedef struct dstar {
    char **value;
    int mem_len;
} dstar_t;

typedef struct dlist{
    char *value;
    int mem_len;
} dlist_t;

dlist_t *init_dlist();
void sh_dlist(dlist_t *to_sh);
void *push_dlist(dlist_t *to_push, char *str);
void clear_dlist(dlist_t *to_clear);
void re_dstar(dstar_t *to_re);
void push_dstar(dstar_t *to_push, char const *value);
char *pop_dstar(dstar_t *to_pop);
dstar_t *init_dstar();
void fill_no(dstar_t *strr);
int my_nolen(dstar_t *dt);
void sh_dstar(dstar_t *dt);

#endif /* !MY_L_H_ */