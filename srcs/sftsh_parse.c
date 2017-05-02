/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:51:08 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/19 21:02:53 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_expand.h"
#include "sftsh_exec.h"
#include "sftsh_find_x.h"
#include "sftsh_builtins.h"
#include "sftsh_types.h"
#include "sftsh_parse.h"

int		is_delimiter(char *str)
{
	return (*str == ';' || *str == '|');
}

static int	count_args(char **tokens, int ix)
{
	int		num_items;

	num_items = ix;
	while (tokens[ix] && !is_delimiter(tokens[ix]))
		++ix;
	return (ix - num_items);
}

static t_command	*dummy(char type)
{
	t_command	*ret;

	if ((ret = (t_command *)malloc(sizeof(t_command))))
	{
		ret->path = ft_strnew(1);
		ret->path[0] = type;
		ret->path[1] = '\0';
		ret->builtin_id = -1;
		ret->num_args = 0;
		ret->args = (void *)0;
		ret->envp = (void *)0;
		ret->next = (void *)0;
	}
	return (ret);
}

static void	add_a_command(t_command **list, char **tokens, char **envp, int *ix)
{
	int		num_args;
	int		j;
	char	**args;
	char	action;
	t_command	*cmd;

	num_args = count_args(tokens, *ix);
	if (!(args = (char **)malloc((num_args + 1) * sizeof(char *))))
	{
		write(2, "memory error\n", 13);
		exit(0);
	}
	j = 0;
	while (tokens[*ix] && !is_delimiter(tokens[*ix]))
		args[j++] = ft_strdup(tokens[(*ix)++]);
	args[j] = (void *)0;
	if (tokens[*ix] && is_delimiter(tokens[*ix]))
		action = tokens[(*ix)++][0];
	else
		action = '\0';
	add_command(list, create_command(args, envp, num_args));
	if (action)
		add_command(list, dummy(action));
}

t_command	*parse(char **tokens, char **envp)
{
	t_command	*commands;
	t_command	*tmp;
	int			i;

	commands = (void *)0;
	expand_tokens(tokens, envp);
	i = 0;
	while (tokens[i])
		add_a_command(&commands, tokens, envp, &i);
	return (commands);
}
