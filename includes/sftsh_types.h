/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:12:50 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/05 11:10:23 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_TYPES_H
# define SFTSH_TYPES_H

# include <unistd.h>
# include <stdlib.h>

# define BUFF_SIZE 64

typedef struct			s_string
{
	char				*text;
	int					len;
}						t_string;

typedef struct			s_command
{
	char				*path;
	int					builtin_id;
	int					num_args;
	char				**args;
	char				***envp;
	struct s_command	*next;
}						t_command;

typedef struct			s_coord
{
	size_t				x;
	size_t				y;
}						t_coord;

t_string				*create_str(char *str);
t_string				*append_str(t_string *str, char c);
t_string				*insert_str(t_string *str, char c, int ix);
t_string				*remove_str(t_string *str, int ix);
t_string				*join_strs(t_string **arr, int len, char glue);
void					free_str(t_string **str);
void					free_strarr(t_string ***strs, int len);

t_command				*create_command(char **args, char ***env, int num_args);
void					add_command(t_command **queue, t_command *command);
t_command				*pop_command(t_command **stack);
void					free_command(t_command *command);

t_coord					*create_coord(size_t z, size_t y);

#endif
