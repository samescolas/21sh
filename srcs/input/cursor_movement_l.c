/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:36:43 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/10 10:54:36 by sescolas         ###   ########.fr       */
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
	int	tmp;
	if (shell->ix->x == 0)
	{
		if (shell->ix->y > 0)
		{
			shell->curr->y -= 1;
			tmp = shell->input[shell->ix->y - 1]->len;
			if (shell->curr->y == shell->strt->y)
				tmp += (shell->prompt[0]->len + 1);
			shell->curr->x = tmp % shell->term->x;
			write_return((void *)0, shell->curr, 0);
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
	move_cursor_left(shell);
	move_ix_left(shell);
}
