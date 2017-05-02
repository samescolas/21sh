/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_funcs2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 12:50:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/19 09:57:22 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
static void		set_env_val(char ***env, char *str)
{
	char	*var;
	int		len;

	len = ft_strfind(str, '=') - 1;
	var = ft_strsub(str, 0, len + 1);
	if (get_env(*env, var))
		set_env(*env, var, &str[len + 2]);
	else
		append_env(env, str);
}

int				sftsh_env(t_command *command)
{
	char		**envp;
	t_tkn		*arg;
	t_command	*new_cmd;

	arg = command->args;
	envp = copy_env(command->env);
	while (arg)
	{
		if (((char *)(arg->data))[0] == '-')
		{
			if (!arg->next)
				return (0);
			if (((char *)(arg->data))[1] == 'P')
			{
				arg = arg->next;
				set_env(envp, "PATH", arg->data);
			}
		}
		else if (ft_strchr(arg->data, '='))
			set_env_val(&envp, arg->data);
		else //((builtin(arg->data) >= 0) || (find_path(arg->data, envp)))
			break ;
		arg = arg->next;
	}
	if (arg)
	{
		command->path = arg->data;
		command->env = envp;
		command->next = NULL;
		if (builtin(arg->data) >= 0)
		{
			command->args = arg->next;
			call_builtin(command);
		}
		else
		{
			if (!(command->path = find_path(command->path, command->env)))
			{
				write(2, "env: ", 5);
				write(2, arg->data, ft_strlen(arg->data));
				write(2, ": No such file or directory\n", 28);
			}
			else
			{
				command->args = arg;
				exec_command(command);
			}
		}
	}
	else
		while (*envp)
			ft_putendl(*(envp++));
	return (0);
}
*/
