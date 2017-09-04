/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:48:46 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 15:02:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "ft_termcap.h"
#include "movement.h"

void	move_ix_up(t_sh *shell)
{
	if (shell->ix->y == 0)
		return ;
	shell->ix->y -= 1;
	if (shell->input[shell->ix->y]->len <= (int)shell->ix->x)
		shell->ix->x = shell->input[shell->ix->y]->len;
}

void	move_cursor_up(t_sh *shell)
{
	int		to_move;

	if (shell->ix->y == 0)
		return ;
	to_move = ((shell->ix->x + 1) / shell->term->x) + 1;
	shell->curr->y -= to_move;
	if (shell->curr->x > shell->input[shell->ix->y - 1]->len % shell->term->x)
		shell->curr->x = shell->input[shell->ix->y - 1]->len % shell->term->x;
	if (shell->ix->y == 1)
		shell->curr->x += shell->prompt[0]->len + 1;
	ft_move_cursor(K_UP, to_move);
	write(1, "\r", 1);
	ft_move_cursor(K_RIGHT, shell->curr->x);
}

void	move_up(t_sh *shell)
{
	move_cursor_up(shell);
	move_ix_up(shell);
}
