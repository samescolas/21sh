/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/26 13:45:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 12:11:50 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "sftsh_types.h"
#include "../libft/libft.h"
#include <sys/wait.h>
#include <unistd.h>

# define MAX_PATHLEN 512
# define MAX_DEPTH
# define NUM_BUILTINS 9
# define BUFF_SIZE 32

# define DEF "\x1B[0m"
# define RED "\x1B[31m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CY1 "\x1B[36m"
# define CY2 "\x1B[37m"
# define CY3 "\x1B[96m"
# define BK2 "\x1B[90m"
# define BL2 "\x1B[94m"
# define MG2 "\x1B[95m"

//void		raw_mode(void);
//void		reset_settings(void);

char		**copy_env(char **envp);
void		append_env(char ***envp, char *str);
char		*get_env(char **envp, char *val);
void		set_env(char **envp, char *variable, char *value);
void		restore_env(char **envp, char **copy);

int			exec_command(t_command *command);
//t_command	*create_command(char *path, t_tkn *args, char **envp);
void		free_command(t_command *command);
t_command	*parse_command(char *command, char **envp);

t_tkn		*create_list_item(void *data, size_t size);
void		push_list(t_tkn **list, t_tkn *node);
t_tkn		*pop_list(t_tkn **list);
void		append_list(t_tkn **list, t_tkn *node);

int			call_func(char *command, char *envp[]);
int			builtin(char *command);
int			call_builtin(t_command *command);
int			sftsh_cd(t_command *command);
int			sftsh_echo(t_command *command);
int			sftsh_exit(t_command *command);
int			sftsh_env(t_command *command);

void		autocomplete(char *text, unsigned int *cursor_position);

char		*find_path(char *command, char **envp);
int			valid_bracket(char *command);
//int			read_line(char **line);
int			is_valid_command(char *command);
t_tkn		*get_tokens(char *command);
void		change_dir(char *path, char **envp);
char		*expand_tilde(char *path, char **envp);
char		**get_args(char *str);
char		*prompt(char *p, char *color);
char		*get_color(char *arg);

int			ft_strcount(char *str, char c);

int			is_close_bracket(char c);
int			is_open_bracket(char c);
int			is_bracket(char c);

#endif
