/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** sig error
*/

#ifndef SIGNAL_ERRORS_H_
#define SIGNAL_ERRORS_H_

#include <signal.h>

#define NB_ERRORS 10

const int SIG_ERRORS[] = {SIGBUS,
                        SIGFPE,
                        SIGILL,
                        SIGQUIT,
                        SIGSEGV,
                        SIGSYS,
                        SIGTRAP,
                        SIGXCPU,
                        SIGXFSZ,
                        SIGABRT};

const char *ERRORS[] = {"Bus error",
                        "Floating exception",
                        "Illegal instruction",
                        "Quit",
                        "Segmentation fault",
                        "Bad system call",
                        "Trace/BTP trap",
                        "Cputime limit exceeded",
                        "Filesize limit exceeded",
                        "Abort"};

const int ERRORS_LEN[] = {9,
                        18,
                        19,
                        4,
                        18,
                        15,
                        14,
                        22,
                        23,
                        5};

#endif /* !SIGNAL_ERRORS_H_ */
