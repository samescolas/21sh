/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_find_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:50:56 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 18:24:10 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_env.h"
#include "sftsh_find_x.h"

char		*find_path(char *command, char **envp)
{
	char	**paths;
	char	*test_path;
	char	*cmd;
	char	*tmp;

	if ((tmp = ft_strchr(command, ';')))
		*tmp = '\0';
	cmd = ft_strjoin((command[0] == '/' ? "" : "/"), command);
	paths = ft_strsplit(get_env(envp, "PATH"), ':');
	while (*paths)
	{
		test_path = ft_strjoin(*(paths++), cmd);
		if (access(test_path, X_OK) == 0)
		{
			ft_strdel(&cmd);
			return (test_path);
		}
		ft_strdel(&test_path);
	}
	test_path = ft_strjoin(getcwd((void *)0, MAX_PATHLEN), cmd);
	if (access(test_path, X_OK) == 0)
	{
		ft_strdel(&cmd);
		return (test_path);
	}
	ft_strdel(&test_path);
	/* free paths, get_env call, and getcwd call... */
	test_path = (void *)0;
	return ((void *)0);
}
