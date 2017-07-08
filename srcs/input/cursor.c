/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 15:19:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/08 16:23:55 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "ft_termcap.h"

/*
** Move cursor to last character on the line
*/
void	snapback(t_sh *shell)
{
	if (!shell)
		exit(0);
	return ;
}

void	move_ix_left(t_sh *shell)
{
	if (shell->ix->x == 0 && shell->ix->y > 0)
		shell->ix->x = shell->input[--(shell->ix->y)]->len;
	else if (shell->ix->x > 0)
		shell->ix->x -= 1;
}

/*
** Move cursor left one position. Handles wrapping and validation.
** First checks whether or not we're on the first line, and if so,
** moves to the line above (if one exists) and move left otherwise.
*/
void	move_cursor_left(t_sh *shell)
{
	if (shell->ix->x == 0)
	{
		if (shell->ix->y > 0)
		{
			//shell->ix->x = shell->input[--(shell->ix->y)]->len;
			shell->curr->x = shell->ix->x % shell->term->x;
			shell->curr->y -= 1;
			ft_move_cursor(K_UP, 1);
			write(1, "\r", 1);
			ft_move_cursor(K_RIGHT, shell->curr->x - 1);
		}
	}
	else if (shell->curr->x == 0)
	{
		//shell->ix->x -= 1;
		shell->curr->x = shell->term->x - 1;
		shell->curr->y -= 1;
		ft_move_cursor(K_UP, 1);
		write(1, "\r", 1);
		ft_move_cursor(K_RIGHT, shell->curr->x);
		
	}
	else
	{
		//shell->ix->x -= 1;
		shell->curr->x -= 1;
		ft_move_cursor(K_LEFT, 1);
	}
}

void	move_left(t_sh *shell)
{
	move_ix_left(shell);
	move_cursor_left(shell);
}

void	move_right(t_sh *shell)
{
	if (!shell)
		exit(0);
	return ;
}

void	move_up(t_sh *shell)
{
	if (!shell)
		exit(0);
	return ;
}

void	move_down(t_sh *shell)
{
	if (!shell)
		exit(0);
	return ;
}
