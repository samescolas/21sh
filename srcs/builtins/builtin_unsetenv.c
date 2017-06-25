/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 12:02:58 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/29 16:09:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "sftsh_types.h"
#include "sftsh_env.h"

static int	ft_in(char *str, char **arr, int arr_size)
{
	int	i;

	i = -1;
	while (++i < arr_size)
		if (ft_strncmp(str, arr[i], ft_strlen(arr[i])) == 0)
			return (1);
	return (0);
}

static void	unset_env_vars(char ***envp, char **var_list, int num_args)
{
	char	**ret;
	int		size;
	int		i;

	size = 0;
	i = -1;
	while ((*envp)[++i])
		if (!ft_in((*envp)[i], var_list, num_args))
			++size;
	if (!(ret = (char **)malloc((size + 2) * sizeof(char *))))
		return ;
	i = -1;
	size = 0;
	while ((*envp)[++i])
	{
		if (!ft_in((*envp)[i], var_list, num_args))
			ret[size++] = (*envp)[i];
		else
			ft_strdel(&(*envp)[i]);
	}
	ret[size] = (void *)0;
	free(*envp);
	*envp = ret;
}

int			sftsh_unsetenv(t_command *command)
{
	unset_env_vars(command->envp, &command->args[1], command->num_args - 1);
	return (0);
}
