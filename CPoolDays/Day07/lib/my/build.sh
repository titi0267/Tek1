#!/bin/sh

gcc -c *.c
ar rc libmy.a *.o
rm *.o
