/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_r.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:50:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/09 12:49:32 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "ft_termcap.h"
#include "movement.h"

void	move_ix_right(t_sh *shell)
{
	if ((int)shell->ix->x == shell->input[shell->ix->y]->len)
	{
		if (shell->ix->y < shell->lines - 1)
		{
			shell->ix->x = 0;
			shell->ix->y += 1;
		}
	}
	else
		shell->ix->x += 1;
}

void	move_cursor_right(t_sh *shell)
{
	if ((int)shell->ix->x == shell->input[shell->ix->y]->len)
	{
		if (shell->ix->y < shell->lines - 1)
		{
			shell->curr->x = 0;
			shell->curr->y += 1;
			ft_move_cursor(K_DOWN, 1);
			write(1, "\r", 1);
		}
	}
	else if (shell->curr->x == shell->term->x - 1)
		wrap_right(shell);
	else
	{
		shell->curr->x += 1;
		ft_move_cursor(K_RIGHT, 1);
	}
}

void	move_right(t_sh *shell)
{
	move_cursor_right(shell);
	move_ix_right(shell);
}
