##
## EPITECH PROJECT, 2021
## 106 bombyx by Maxime HOFFBECK & Timothy CONIEL
## File description:
## 106bombyx.py
##

import sys

def help():
    try:
        if sys.argv[1] == "-h" and len(sys.argv) == 2:
            print('USAGE\n    python main.py n [k | i0 i1]')
            print('DESCRIPTION')
            print('    n      number of first generation individuals')
            print('    k      growth rate from 1 to 4')
            print('    i0     initial generation (included)')
            print('    i1     final generation (included)')
    except IndexError:
        exit (84)

def nbr_arg():
    if len(sys.argv) == 3:
        return (0)
    elif len(sys.argv) == 4:
        return (1)
    else:
        return (-1)

def two_arg(n, k):
    x = float(n)
    y = float(n)
    print("1 %.2f" % float(n))
    for i in range(2, 101):
        x = (float(k) * y) * ((1000 - y) / 1000)
        print(str(i) + " " + str("%.2f" % x))
        y = x

def three_arg(n):
    x = float(n)
    y = float(n)
    i0 = sys.argv[2]
    i1 = sys.argv[3]
    #print(str("%.2f" % float(k)) + str(" %.2f" % float(x)))
    for k in range(100, 401):
        for i in range(1, int(i0)):
            x = ((k / 100) * y) * ((1000 - y) / 1000)
            y = x
        for h in range(int(i0), int(i1) + 1):
            x = ((k / 100) * y) * ((1000 - y) / 1000)
            print(str("%.2f" % (k / 100)) + " " + str("%.2f" % x))
            y = x
        k += 1


if __name__ == '__main__':
    i = nbr_arg()
    if i != 1 and i != 0:
        exit(84)
    n = sys.argv[1]
    k = sys.argv[2]
    if i == 0:
        two_arg(n, k)
    if i == 1:
        three_arg(n)
    help()