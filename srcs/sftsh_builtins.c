/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:04:17 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/19 09:57:36 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_builtins.h"
#include "sftsh_types.h"

int		builtin(char *command)
{
	const char	*builtin_str[NUM_BUILTINS];
	int		ret;

	builtin_str[(ret = 0)] = "cd";
	builtin_str[1] = "env";
	builtin_str[2] = "getenv";
	builtin_str[3] = "setenv";
	builtin_str[4] = "help";
	builtin_str[5] = "col";
	builtin_str[6] = "ps1";
	builtin_str[7] = "echo";
	builtin_str[8] = "exit";
	while (ret < NUM_BUILTINS)
		if (ft_strcmp(builtin_str[ret++], command) == 0)
			return (ret - 1);
	return (-1);
}
/*
int		call_builtin(t_command *command)
{
	int	(*builtins[NUM_BUILTINS])(t_command *);

	builtins[0] = &sftsh_cd;
	builtins[1] = &sftsh_env;
	builtins[7] = &sftsh_echo;
	builtins[8] = &sftsh_exit;
	if (command->builtin < NUM_BUILTINS)
		return ((builtins[command->builtin])(command));
	return (0);
}
*/
