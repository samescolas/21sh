/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_env2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:48:52 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/15 13:05:45 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_vars.h"

void	delete_env(char ***envp)
{
	ft_strarrdel(envp);
	free(*envp);
	envp = (void *)0;
}

char	**create_env(char ***envp)
{
	char	**ret;
	char	*cwd;

	cwd = getcwd((void *)0, MAX_PATHLEN);
	if (!(ret = (char **)malloc(6 * sizeof(char *))))
		return ((void *)0);
	ret[0] = ft_strjoin(ft_strdup("PWD="), cwd);
	ret[1] = ft_strjoin("TERM=", DEFAULT_TERM);
	ret[2] = ft_strjoin("PATH=", DEFAULT_PATH);
	ret[3] = ft_strjoin("HOME=", cwd);
	ret[4] = ft_strjoin("OLDPWD=", cwd);
	ret[5] = (void *)0;
	*envp = ret;
	ft_strdel(&cwd);
	return (ret);
}
