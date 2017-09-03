/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:28:47 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 11:51:58 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "ft_termcap.h"
#include "../../libft/libft.h"

/*
int		update_vimarrow(int key, t_sh *shell)
{
	if (key == 'h' || key == KEY_LEFT)
		return (update_arrowkey(KEY_LEFT, sess));
	else if (key == 'l' || key == KEY_RIGHT)
		return (update_arrowkey(KEY_RIGHT, sess));
	else if (key == 'j' || key == KEY_DOWN)
		return (update_arrowkey(KEY_DOWN, sess));
	else if (key == 'k' || key == KEY_UP)
		return (update_arrowkey(KEY_UP, sess));
	return (1);
}
*/

int		update_vimarrow(int key, t_sh *shell)
{
	if (key == 'h')
		key = KEY_LEFT;
	else if (key == 'l')
		key = KEY_RIGHT;
	else if (key == 'j')
		key = KEY_DOWN;
	else if (key == 'k')
		key = KEY_UP;
	return (update_arrowkey(key, shell));
}

int		update_vimword(int key, t_sh *shell)
{
	if (ft_toupper(key) == 'W')
	{
		if (shell->ix->x == shell->input[shell->ix->y]->len)
			return (1);
		if (key == 'W')
			shell->ix->x += ft_strfind(&shell->input[shell->ix->y][shell->ix->x + 1], ' ');
		else
		{
			while (ft_isalpha(shell->input[shell->ix->y][shell->ix->x]))
				move_right(shell);
		}
	}
	else if (ft_toupper(key) == 'B')
	{
		if (shell->ix->x == 0)
			return (1);
		if (key == 'B')
		{
			while (shell->ix->x > 0)
				if (ft_isalpha(shell->input[shell->ix->y][--(shell->ix->x)]))
					break ;
		}
		else
		{
			while (shell->ix->x > 0)
				if (shell->input[shell->ix->y][--(shell->ix->x)] == ' ')
					break ;
		}
	}
	else
		return (1);
	return (0);
}
