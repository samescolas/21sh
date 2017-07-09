/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 08:44:02 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/09 13:01:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_types.h"

int		ft_putc(int c)
{
	write(STDOUT_FILENO, &c, 1);
	return (0);
}

void	ft_move_cursor(char *direction, int n)
{
	while (n--)
		tputs(direction, 1, ft_putc);
}

void	ft_putstr_mode(char *str, char *mode)
{
	if (!mode)
	{
		tputs(str, 1, ft_putc);
		return ;
	}
	if (mode == US || mode == MR)
		tputs(mode, 1, ft_putc);
	else
		return ;
	tputs(str, 1, ft_putc);
	tputs((mode == US ? UE : ME), 1, ft_putc);
}

void	ft_hide_cursor(void)
{
	tputs(VI, 1, ft_putc);
}

void	ft_write_loc(t_string *str, t_coord pos)
{
	tputs(tgoto(CM, pos.x, pos.y), 1, ft_putc);
	if (str)
		write(1, str->text, str->len);
}
