/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:20:33 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 10:08:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_env.h"
#include "sftsh_types.h"
#include "sftsh_vars.h"
#include "sftsh_builtins.h"
#include "../../libft/libft.h"

static int	sftsh_cd_err(int num_args, ...)
{
	va_list	args;
	char	*msg;
	int		i;

	va_start(args, num_args);
	i = -1;
	while (++i < num_args)
	{
		msg = va_arg(args, char *);
		write(2, msg, ft_strlen(msg));
	}
	if (num_args > 1)
		ft_strdel(&msg);
	write(2, "\n\r", 2);
	va_end(args);
	return (1);
}

static char	*get_full_path(t_command *cmd)
{
	char	*ret;

	if (cmd->num_args == 1)
	{
		if ((ret = ft_strdup(get_env(*cmd->envp, "HOME"))))
			return (ret);
		else
			return (ft_strdup("/"));
	}
	else if (cmd->num_args == 2)
	{
		if (cmd->args[1][0] == '-' && !cmd->args[1][1])
		{
			if ((ret = ft_strdup(get_env(*cmd->envp, "OLDPWD"))))
				return (ret);
			else if ((ret = ft_strdup(get_env(*cmd->envp, "HOME"))))
				return (ret);
			else
				return (ft_strdup("/"));
		}
		else
			return (ft_strdup(cmd->args[1]));
	}
	else
		return ((void *)0);
}

static int	is_dir(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) < 0)
		return (0);
	return (f_stat.st_mode & S_IFDIR);
}

int			sftsh_cd(t_command *cmd)
{
	char	*path;
	char	*cwd;

	if (!(path = get_full_path(cmd)))
		return (sftsh_cd_err(1, "cd: too many arguments"));
	if (access(path, F_OK) == 0)
	{
		if (access(path, R_OK) != 0)
			return (sftsh_cd_err(2, "cd: permission denied: ", path));
		if (is_dir(path))
		{
			cwd = getcwd((void *)0, MAX_PATHLEN);
			set_env(*cmd->envp, "OLDPWD", cwd);
			chdir(path);
			getcwd(cwd, MAX_PATHLEN);
			set_env(*cmd->envp, "PWD", cwd);
			ft_strdel(&cwd);
			ft_strdel(&path);
			return (0);
		}
		else
			return (sftsh_cd_err(2, "cd: not a directory: ", path));
	}
	else
		return (sftsh_cd_err(2, "cd: no such file or directory: ", path));
}
