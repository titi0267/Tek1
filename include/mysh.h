/*
** EPITECH PROJECT, 2021
** mysh
** File description:
** mysh header
*/

#ifndef MYSH_H_
#define MYSH_H_

#define SIGNAL_QUIT_VALUE 128

#define READ_FILE_REDIRECT 1
#define HEREDOC_REDIRECT 2
#define WRITE_REDIRECT 3
#define WRITE_APPEND_REDIRECT 4

typedef struct shell_s {
    char **env;
    char *prev_cd;
    int stdin;
    int stdout;
    int in_fd;
    int out_fd;
    unsigned char ret;
    int prev_pid;
    int subcmd_len;
} shell_t;

void exit_program(int ret);
char **copy_env(char **env);

char *get_env_value(char *name, char **env);
char *create_variable(char *name, char *value);
void set_variable(char *name, char *value, char **env);
char **clone_env(char **env, int *size, int bonus_size);
char **remove_env_variable(char **args, char **env);

int check_valid_env_name(char *name);
int get_env_name_length(char *line);

void add_char(char **str, int len, char c);
int count_char(char *str, char c);
void free_array(char **array);
void print_err(char *str);
int str_to_int(char *str);

/* INPUT */

char *read_input(char *prefix, int prefix_len);
char *get_input(char *prefix, int prefix_len);
int check_input(char **cmds);

char **split_commands(char *str);
int read_commands(char *str, char **cmds);
int add_command(char **cmds, int cmd, char *start, int len);

/* CMD */

char **split_command_into_subcmds(char *str);
char **split_command_into_args(char *cmd);

void execute_commands(char **cmds, shell_t *shell);
void execute_subcommands(char **sub_cmds, shell_t *shell);
int execute_command(char **args, char next, shell_t *shell);
int builtin_cmd(char **args, shell_t *shell);
int check_null_cmd(char **args, shell_t *shell);

int setup_redirections(char **args, int fds[3], char next, shell_t *shell);
int setup_all_file_redirection(char **args, int fds[3], shell_t *shell);
int get_file_redirection(char ***args);
int check_multiple_file_redirect(int file_red, char *file_in, char *file_out);
int check_redirections(int redirections, char next, int fds[3], shell_t *shell);

int setup_file_redirection(char *filename,
int fds[3], int file_red, shell_t *shell);
int setup_input_file(char *filename, int fds[3], shell_t *shell);
int setup_input_heredoc(char *eof, int fds[3], shell_t *shell);
int setup_output_file(char *filename, int fds[3], shell_t *shell);
int setup_output_append_file(char *filename, int fds[3], shell_t *shell);

int setup_pipes(int fds[3], char next, shell_t *shell);
void check_pipe_fd_validity(int pipefd[2]);

void heredoc(char *eof, int out_fd);

int run_file(char *bin, char **args, char next, shell_t *shell);
int analyse_status_value(int status);
void print_sig_error(int status, int sig);

char *search_binary(char **args, shell_t *shell);
char *search_bin_in_path(char **args, shell_t *shell);
char *search_binary_into_dir(char **args, char *str, int len);
char dir_contains_file(char *name, char *path, int len);

char is_binary_filepath(char *bin, int len);
char is_valid_binary(char *path);
char *get_binary_path(char *name, char *start, int len);
int change_dir(char *dir, shell_t *shell);
void read_line(int fd, char **str, int *len);
int subcmd_len(char **subcmd);
int wait_all_children(shell_t *shell);

#endif /* !MYSH_H_ */
