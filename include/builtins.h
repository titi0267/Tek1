/*
** EPITECH PROJECT, 2021
** minishell
** File description:
** builtins commands
*/

#ifndef BUILTINS_H_
#define BUILTINS_H_

typedef int (*builtin_fct_t)(char **args, shell_t *shell);

int cd_cmd(char **args, shell_t *shell);
int env_cmd(char **args, shell_t *shell);
int setenv_cmd(char **args, shell_t *shell);
int unsetenv_cmd(char **args, shell_t *shell);
int exit_cmd(char **args, shell_t *shell);

#define BUILTINS_NB 5

const char *BUILTINS[] = {"cd",
                        "env",
                        "setenv",
                        "unsetenv",
                        "exit"};

const int BUILTINS_LEN[] = {2,
                            3,
                            6,
                            8,
                            4};

builtin_fct_t BUILTINS_FCT[] = {&cd_cmd,
                            &env_cmd,
                            &setenv_cmd,
                            &unsetenv_cmd,
                            &exit_cmd};

#endif /* BUILTINS_H_ */