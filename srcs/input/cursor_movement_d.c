/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement_d.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:48:36 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 14:43:20 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "ft_termcap.h"
#include "movement.h"

void	move_ix_down(t_sh *shell)
{
	if (shell->ix->y + 1 >= shell->lines)
		return ;
	shell->ix->y += 1;
	if (shell->input[shell->ix->y]->len <= (int)shell->ix->x)
		shell->ix->x = shell->input[shell->ix->y]->len;
}

void	move_cursor_down(t_sh *shell)
{
	int		to_move;

	if (shell->ix->y + 1 >= shell->lines)
		return ;
	to_move = (shell->input[shell->ix->y]->len / shell->term->x) + 1;
	shell->curr->y += to_move;
	if (shell->curr->x > (shell->input[shell->ix->y]->len % shell->term->x))
		shell->curr->x = shell->input[shell->ix->y]->len % shell->term->x;
	ft_move_cursor(K_DOWN, to_move);
}

void		move_down(t_sh *shell)
{
	move_cursor_down(shell);
	move_ix_down(shell);
}
