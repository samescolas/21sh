/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:36:43 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 14:18:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_utils.h"
#include "ft_termcap.h"
#include "../../libft/libft.h"

void	wrap_left(t_sh *shell)
{
	shell->curr->x = shell->term->x - 1;
	shell->curr->y -= 1;
	ft_move_cursor(K_UP, 1);
	write(1, "\r", 1);
	ft_move_cursor(K_RIGHT, shell->curr->x);
}

void	wrap_right(t_sh *shell)
{
	shell->curr->x = 0;
	shell->curr->y += 1;
	ft_move_cursor(K_DOWN, 1);
	write(1, "\r", 1);
}

void	write_return(char *str, t_coord *start, int padding)
{
	ft_putstr(str);
	while (padding--)
		write(1, " ", 1);
	ft_write_loc((void *)0, *start);
}

void	clear_line(int len)
{
	write(1, "\r", 1);
	while (len--)
		write(1, " ", 1);
	write(1, "\r", 1);
}

void	write_arr_return(t_string **arr, t_coord *start, int len)
{
	int		ix;
	int		term_width;

	ix = 0;
	term_width = get_term_width();
	clear_line(term_width);
	write(1, arr[ix]->text, arr[ix]->len);
	while (++ix < len)
	{
		write(1, "\n", 1);
		clear_line(term_width);
		write(1, arr[ix]->text, arr[ix]->len);
	}
	ix = -1;
	while (++ix < len)
	{
		write(1, "\n\r", 2);
		clear_line(term_width);
	}
	ft_write_loc((void *)0, *start);
}
