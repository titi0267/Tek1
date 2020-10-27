#pragma once
void ex_numbers(number_t *num1,number_t *num2);
void first_oc(char *num1,char *num2,int *first,int *second);
int my_nblen(char *num);
number_t *calc_t(number_t *one,number_t *two,opossom_t *ops);
void det_operation(number_t *num1,number_t *num2,opossom_t *ops);
void greater(number_t *num1,number_t *num2);
void clear_o(char *witho);
void det_signs(char *ar1,char *ar2,int *one,int *two);
number_t *adapt_numbers(char **ar1,char **ar2,number_t *one,number_t *two);
void recreate_number(char **ar1,char **ar2);
void destroy_minus(char *ar_one);
