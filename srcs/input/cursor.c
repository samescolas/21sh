/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 15:19:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/08 15:37:37 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Move cursor to last character on the line
*/
void	snapback(t_sh *shell)
{

}

/*
** Move cursor left one position. Handles wrapping and validation
*/
void	move_left(t_sh *shell)
{
	/* If at the beginning of current line */
	if (shell->ix->x == 0)
	{
		/* If not the first line */
		if (shell->ix->y > 0)
		{
			shell->ix->y -= 1;
			shell->ix->x = shell->term->x;
		}
	}
}

void	move_right(t_sh *shell)
{

}

void	move_up(t_sh *shell)
{

}

void	move_down(t_sh *shell)
{

}
