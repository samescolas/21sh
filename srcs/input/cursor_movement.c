/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:36:43 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/09 13:10:11 by sescolas         ###   ########.fr       */
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

void	write_return(char *str)
{
	t_coord	*return_position;

	return_position = get_cursor_position();
	ft_putstr(str);
	ft_write_loc((void *)0, *return_position);
	delete_coord(&return_position);
}
