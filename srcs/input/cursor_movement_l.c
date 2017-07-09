/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:36:43 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/08 16:56:53 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "ft_termcap.h"
#include "movement.h"

void	move_ix_left(t_sh *shell)
{
	if (shell->ix->x == 0 && shell->ix->y > 0)
		shell->ix->x = shell->input[--(shell->ix->y)]->len;
	else if (shell->ix->x > 0)
		shell->ix->x -= 1;
}

void	move_cursor_left(t_sh *shell)
{
	if (shell->ix->x == 0)
	{
		if (shell->ix->y > 0)
		{
			shell->curr->x = shell->ix->x % shell->term->x;
			shell->curr->y -= 1;
			ft_move_cursor(K_UP, 1);
			write(1, "\r", 1);
			ft_move_cursor(K_RIGHT, shell->curr->x - 1);
		}
	}
	else if (shell->curr->x == 0)
		wrap_left(shell);
	else
	{
		shell->curr->x -= 1;
		ft_move_cursor(K_LEFT, 1);
	}
}

void	move_left(t_sh *shell)
{
	move_ix_left(shell);
	move_cursor_left(shell);
}
