/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_find_executable.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 09:51:06 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_utils.h"
#include "sftsh_env.h"
#include "sftsh_vars.h"

static char	*check_current_directory(char *cmd)
{
	char	*test_path;
	char	*tmp_path;
	char	*cwd;

	cwd = getcwd((void *)0, MAX_PATHLEN);
	tmp_path = (cmd[0] == '/' ? ft_strdup(cmd) : ft_strjoin("/", cmd));
	test_path = ft_strjoin(cwd, tmp_path);
	ft_strdel(&tmp_path);
	if (access(test_path, F_OK) == 0)
	{
		ft_strdel(&cwd);
		return (test_path);
	}
	ft_strdel(&cwd);
	ft_strdel(&test_path);
	return ((void *)0);
}

static char	*get_next_path(char **paths, char *cmd, int *ix)
{
	char	*cmd_str;
	char	*tmp;

	if (!paths[++(*ix)])
	{
		ft_strarrdel(&paths);
		free(paths);
		paths = (void *)0;
		return ((void *)0);
	}
	cmd_str = (cmd[0] == '/' ? ft_strdup(cmd) : ft_strjoin("/", cmd));
	tmp = ft_strjoin(paths[*ix], cmd_str);
	ft_strdel(&cmd_str);
	return (tmp);
}

static char	*find_matching_path(char *command, char **paths)
{
	char	*ret;
	char	*tmp;
	int		i;

	ret = (void *)0;
	if (!paths || !*paths)
		return ((void *)0);
	i = -1;
	while ((tmp = get_next_path(paths, command, &i)))
	{
		if (access(tmp, F_OK) == 0)
			ret = (ret && access(ret, X_OK) == 0 ? ret : ft_strdup(tmp));
		ft_strdel(&tmp);
	}
	if (ret && access(ret, X_OK) == 0)
		return (ret);
	if ((tmp = check_current_directory(command)))
	{
		ft_strdel(&ret);
		return (tmp);
	}
	if (ret)
		tmp = ft_strjoin("access denied: ", ft_strrchr(ret, '/'));
	ft_strdel(&ret);
	return (tmp);
}

static int	is_dir(char *path)
{
	struct stat	f_stat;

	if (stat(path, &f_stat) < 0)
		return (0);
	return (f_stat.st_mode & S_IFDIR);
}

char		*find_exe_path(char *command, char **envp)
{
	char	*path;

	if (access(command, X_OK) == 0 && !is_dir(command))
		return (ft_strdup(command));
	path = find_matching_path(command, ft_strsplit(get_env(envp, "PATH"), ':'));
	if (!path && access(command, F_OK) != 0)
	{
		ft_putstr("sftsh: what the shell is ");
		ft_putstr(command);
		ft_putendl("?");
		return ((void *)0);
	}
	else if (!path)
		path = ft_strdup(command);
	if (access(path, X_OK) == 0 && !is_dir(path))
		return (path);
	else if (access(path, F_OK) == 0)
	{
		ft_putstr("sftsh: no soup: ");
		ft_putendl(ft_strrchr(path, '/') + 1);
		ft_strdel(&path);
	}
	return ((void *)0);
}
