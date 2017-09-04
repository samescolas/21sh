/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:24:58 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 15:57:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "../libft/libft.h"
#include "sftsh_builtins.h"
#include "sftsh_utils.h"

t_command	*create_command(char **args, char ***envp, int num_args)
{
	t_command	*ret;

	if ((ret = (t_command *)malloc(sizeof(t_command))))
	{
		if ((ret->builtin_id = find_builtin(args[0])) < 0)
			ret->path = find_exe_path(args[0], *envp);
		else
			ret->path = (void *)0;
		if (ret->path == (void *)0 && ret->builtin_id < 0)
		{
			ft_strarrdel(&args);
			args = (void *)0;
			free(ret);
			ret = (void *)0;
			return ((void *)0);
		}
		ret->num_args = num_args;
		ret->args = args;
		ret->envp = envp;
		ret->next = (void *)0;
	}
	return (ret);
}

void		add_command(t_command **queue, t_command *command)
{
	t_command	*tmp;

	if (!queue || !command)
		return ;
	if (!*queue)
		*queue = command;
	else
	{
		tmp = *queue;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = command;
	}
}

t_command	*pop_command(t_command **stack)
{
	t_command	*ret;

	if (!stack || !*stack)
		return ((void *)0);
	if (!(*stack)->next)
	{
		ret = *stack;
		*stack = (void *)0;
		return (ret);
	}
	ret = (void *)0;
	ret = *stack;
	*stack = (*stack)->next;
	return (ret);
}

void		free_command(t_command *command)
{
	if (command->path)
		ft_strdel(&(command->path));
	if (command->args)
		ft_strarrdel(&(command->args));
	command->path = (void *)0;
	command->args = (void *)0;
	command->next = (void *)0;
	command->num_args = 0;
	free(command);
}
