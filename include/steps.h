/*
** EPITECH PROJECT, 2020
** B-CPE-110-STG-1-1-bsbsq-timothe.coniel
** File description:
** steps
*/
#ifndef STEPS_H_
#define STEPS_H_

typedef struct buffer_size {
    int btw_o; // number of . on a line
    int store_btw; //number max of . on a line
    int i; // string array
    int w; //skip the first line with numbers
    int store_nbrbuf; //string array of the biggest number of . on a line
    //int store_nbrline;
    int start_line;
    int carac_l; //number of caracters on a line
    int line;
    int before_n; //postion over first dot of max dots on a line
    int after_n; //postion under first dot of max dots on a line
    int store_enddot;
    int isdot;
    int after_end;
    int before_end;
} buffer_size_t;

#endif /* !STEPS_H_ */