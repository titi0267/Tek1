/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-pushswap-timothe.coniel
** File description:
** op
*/

#ifndef OP_H_
#define OP_H_

typedef struct allowed_op {
    //int sa; //swap first two elements of list a
    //int sb; //same for list b
    int sc; //both at same time
    int pa; //take first element of list b and put in first place of list a
    //int pb; //same but first list a in first list b
    //int ra; //take first element of list a and put it last of list b
    //int rb; //same but first b in last b
    int rr; //two at same time
    //int rra; //same but last a in first a
    //int rrb; //same but last b in first b
    int rrr; //two at same time
} allowed_op_t;


#endif /* !OP_H_ */
