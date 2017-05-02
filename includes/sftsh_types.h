/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:12:50 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/19 21:03:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_TYPES_H
# define SFTSH_TYPES_H

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>

typedef struct			s_tkn
{
	void				*data;
	size_t				size;
	struct s_tkn		*next;
	struct s_tkn		*prev;
}						t_tkn;

typedef struct			s_command
{
	char				*path;
	int					builtin_id;
	int					num_args;
	char				**args;
	char				**envp;
	struct s_command	*next;
}						t_command;

t_command	*create_command(char **args, char **env, int num_args);
void		expand_command(t_command *command);
void		push_command(t_command **stack, t_command *command);
t_command	*pop_command(t_command **stack);
void		add_command(t_command **queue, t_command *command);
void		free_command(t_command *command);
void		free_commands(t_command **stack);

t_tkn		*create_list_item(void *data, size_t size);
void		insert_list(t_tkn **list, t_tkn *node, int (*cmp)(t_tkn *, t_tkn *));
void		append_list(t_tkn **list, t_tkn *node);
void		push_list(t_tkn **list, t_tkn *node);
t_tkn		*pop_list(t_tkn **list);
char		**list_to_arr(t_tkn *list);

#endif
