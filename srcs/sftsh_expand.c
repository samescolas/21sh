/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_expand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:43:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/17 15:18:59 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_env.h"
#include "sftsh_expand.h"

char		*expand_tilde(char *path, char **envp)
{
	char	*ret;
	char	*home;
	int		i;
	int		j;
	int		len;

	if (ft_strchr(path, '~') == (void *)0)
		return (path);
	home = get_env(envp, "HOME");
	len = ft_strlen(home);
	ret = ft_strnew((ft_strcount(path, '~') * (len - 1)) + ft_strlen(path));
	i = -1;
	j = 0;
	while (path[++i])
	{
		if (path[i] == '~')
		{
			ft_strcat(ret, home);
			ft_strcat(ret, "/");
			j += len + 1;
		}
		else if (path [i] == '/' && path[i - 1] && path[i - 1] == '~')
			continue ;
		else
			ret[j++] = path[i];
	}
	ft_strdel(&path); /* this may be a bad idea */
	return (ret);
}

void		expand_tokens(char **tokens, char **envp)
{
	char	**tmp;

	tmp = tokens;
	while (*tmp)
	{
		*tmp = expand_tilde(*tmp, envp);
		++tmp;
	}
}
