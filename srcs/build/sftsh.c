/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:57:44 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/05 19:14:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh.h"
#include "../libft/libft.h"
#include "sftsh_vars.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "sftsh_parser.h"
#include "sftsh_exec.h"
/*
static char	*get_color(char *color)
{
	if (ft_strcmp(color, "default") == 0 || ft_strcmp(color, "def") == 0)
		return (ft_strdup(DEF));
	else if (ft_strcmp(color, "red") == 0 || ft_strcmp(color, "r") == 0)
		return (ft_strdup(RED));
	else if (ft_strcmp(color, "blue") == 0 || ft_strcmp(color, "b") == 0)
		return (ft_strdup(BLU));
	else if (ft_strcmp(color, "magenta") == 0 || ft_strcmp(color, "m") == 0)
		return (ft_strdup(MAG));
	else if (ft_strcmp(color, "c2") == 0)
		return (ft_strdup(CY2));
	else if (ft_strcmp(color, "c3") == 0)
		return (ft_strdup(CY3));
	else if (ft_strcmp(color, "bk2") == 0)
		return (ft_strdup(BK2));
	else if (ft_strcmp(color, "bl2") == 0)
		return (ft_strdup(BL2));
	else if (ft_strcmp(color, "m2") == 0)
		return (ft_strdup(MG2));
	else
		return ((void *)0);
}

static int	delete_prompt(char *prompt[3])
{
	ft_strdel(&prompt[0]);
	ft_strdel(&prompt[1]);
	ft_strdel(&prompt[2]);
	return (0);
}

static void	disp_input(t_string **input, int lines)
{ 
	int		ix;

	ix = -1;
	while (++ix < lines)
	{
		write(1, input[ix]->text, input[ix]->len);
		write(1, "\n", 1);
	}
}
*/

int			sftsh(char ***envp)
{
	//char	c;
	static t_sh		*shell;
	t_string		*tmp;
	t_command		*command;

	ft_putendl("inside sftsh");
	if (!shell)
		shell = create_sh();
	ft_putendl("created shell");
	while (envp && get_command_str(shell) == 0)
	{
		/*if (ft_strncmp(sess->prompt[0], "ps1=", 4) == 0)
		{
			ft_strdel(&sess->prompt[1]);
			sess->prompt[1] = ft_strdup(&sess->prompt[0][4]);
		}
		else if (ft_strncmp(sess->prompt[0], "col=", 4) == 0)
		{
			ft_strdel(&sess->prompt[2]);
			sess->prompt[2] = get_color(ft_strmap(&sess->prompt[0][4], &ft_tolower));
		}
		else if */
		write(1, "\n", 1);
		tmp = join_strs(shell->input, shell->lines, '\n');
		if ((command = parse(tmp->text, envp)))
		{
			if (sftsh_exec(command) == -42)
				break ;
			free_str(&tmp);
		}

		//disp_input(shell->input, shell->lines);
	}
	return (0);
	//return (delete_prompt(sess->prompt));
}
