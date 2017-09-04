/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:12:50 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 18:51:14 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_TYPES_H
# define SFTSH_TYPES_H

# include <unistd.h>
# include <stdlib.h>

typedef struct			s_string
{
	char				*text;
	int					len;
}						t_string;

typedef struct			s_list
{
	t_string			*str;
	struct s_list		*prev;
	struct s_list		*next;
}						t_list;

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

typedef struct			s_sh
{
	t_string			**input;
	t_string			*prompt[2];
	t_string			*cb;
	t_coord				*strt;
	t_coord				*curr;
	t_coord				*ix;
	t_coord				*term;
	t_list				*history;
	size_t				lines;
}						t_sh;

t_string				*create_str(char *str);
t_string				*append_str(t_string *str, char c);
t_string				*insert_str(t_string *str, char c, int ix);
t_string				*remove_str(t_string *str, int ix);
t_string				*join_strs(t_string **arr, int len, char glue);
void					free_str(t_string **str);
void					free_strarr(t_string ***strs, int len);
void					remove_strarr(t_string ***strs, int ix, int len);
t_string				**insert_strarr(t_string ***strs, t_string *str, int ix, int len);

t_list					*create_list_item(char *str);
void					list_add(t_list **list, t_list *new_node);
void					free_list_item(t_list *list);
void					remove_list(t_list **list);

t_command				*create_command(char **args, char ***env, int num_args);
void					add_command(t_command **queue, t_command *command);
t_command				*pop_command(t_command **stack);
void					free_command(t_command *command);

t_coord					*create_coord(size_t z, size_t y);
void					delete_coord(t_coord **coord);

t_sh					*create_sh(void);

#endif
