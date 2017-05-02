/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 13:34:29 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/10 16:22:37 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "debug.h"
#include <dirent.h>

static void	get_commandlist(char *filter)
{
	static t_list *list;
}

static void	display_programs(char *filter, unsigned int *cursor_position)
{
/*	char	**command_list;
	int		ix;

	command_list = get_commands(filter);
	ix = 0;
	while (command_list[ix])
		ft_putendl(command_list[ix++]);
*/
	ft_putendl("programs:");
}

static void	display_filenames(char *filter, unsigned int *cursor_position)
{
	char			*path;
	char			*tmp;
	static DIR		*dir;
	struct dirent	*dp;

	path = getcwd((void *)0, MAX_PATHLEN);
	if (dir == (void *)0)
		if (!(dir = opendir(path)))
			return ;
	if ((dp = readdir(dir)) != NULL)
	{
		write(1, dp->d_name, ft_strlen(dp->d_name));
		ft_strcat(filter, dp->d_name);
		*cursor_position += ft_strlen(dp->d_name);
	}
}

void		autocomplete(char *text, unsigned int *cursor_position)
{
	display_filenames(text, cursor_position);
}
