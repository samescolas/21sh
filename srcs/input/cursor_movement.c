/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:36:43 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/08 16:44:35 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "ft_termcap.h"

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
