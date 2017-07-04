/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:12:50 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 17:19:00 by sescolas         ###   ########.fr       */
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
}

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

t_command				*create_command(char **args, char ***env, int num_args);
t_coord					*create_coord(size_t z, size_t y);
t_command				*pop_command(t_command **stack);
void					add_command(t_command **queue, t_command *command);
void					free_command(t_command *command);

#endif
