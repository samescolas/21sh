/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_funcs1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 10:08:43 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/19 09:57:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "debug.h"

/*
int		sftsh_echo(t_command *command)
{
	t_tkn	*tmp;
	int		no_newline;

	if (!(command->args))
	{
		write(1, "\n", 1);
		return (0);
	}
	tmp = command->args;
	if ((no_newline = (ft_strcmp(command->args->data, "-n") == 0)))
		tmp = tmp->next;
	while (tmp)
	{
		// it would be cool for this to be in color if something existed in *(command->env)
		ft_padstr((char *)(tmp->data), 1, (void *)0);
		tmp = tmp->next;
	}
	if (!no_newline)
		write(1, "\n", 1);
	return (0);
}

int		sftsh_cd(t_command *command)
{
	char	*full_path;

	if (command->args == (void *)0)
		full_path = expand_tilde("~", command->env);
	else if (ft_strcmp(command->args->data, "-") == 0)
		full_path = ft_strdup(get_env(command->env, "OLDPWD"));
	else
		full_path = expand_tilde(command->args->data, command->env);
	if (command->args && command->args->next != NULL)
	{
		write(2, "cd: too many arguments\n", 23);
		return (1);
	}
	if (access(full_path, R_OK) == 0)
	{
		set_env(command->env, "OLDPWD", getcwd((void *)0, MAX_PATHLEN));
		chdir(full_path);
		ft_strdel(&full_path);
		return (0);
	}
	write(2, "cd: no such file or directory: ", 31);
	write(2, command->args->data, command->args->size);
	write(2, "\n", 1);
	return (1);
}

static void	print_help(char *command)
{
	if (ft_strcmp(command, "exit") == 0)
		ft_putendl("there's no such thing as a stupid question");
}

int		sftsh_exit(t_command *command)
{
	if (command->args != NULL && ft_strcmp(command->args->data, "help") == 0)
		print_help("exit");
	// free_command(&command);
	exit(0);
}


static void		set_env_val(char ***env, char *str)
{
	char	*variable;
	int		len;

	len = ft_strfind(str, '=') - 1;
	variable = ft_strsub(str, 0, len + 1);
	if (get_env(*env, variable) != (void *)0)
		set_env(*env, variable, &str[len + 2]);
	else
		append_env(env, str);
}

int		sftsh_env(t_command *command)
{
	char	**envp;

	envp = *(command->env);
	if (command->args != NULL)
	{
		if (((char *)(command->args->data))[0] == '-')
		{
			return (0);
		}
		else
			if (ft_strchr(command->args->data, '='))
				set_env_val(&envp, command->args->data);
	}
	//envp = *(command->env);
	while (*envp)
		ft_putendl(*(envp++));
	return (0);
}
*/
