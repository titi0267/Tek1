##
## EPITECH PROJECT, 2021
## 106 bombyx by Maxime HOFFBECK & Timothy CONIEL
## File description:
## 106bombyx.py
##

import sys

def help():
    try :
        if sys.argv[1] == "-h" and len(sys.argv) == 2:
            print('USAGE\n    ./106bombyx n [k | i0 i1]')
            print('DESCRIPTION')
            print('    n      number of first generation individuals')
            print('    k      growth rate from 1 to 4')
            print('    i0     initial generation (included)')
            print('    i1     final generation (included)')
    except:
        IndexError

def suit_len():
    try:
        x = sys.argv[1]
        y = ''.join(x)
    except:
        TypeError
    z = int(y)
    s = 0
    for i in range(0, z):
        s += 1
        print('', s)
        if int(s) >= int(z):
            break

suit_len()
help()