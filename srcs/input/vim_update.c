/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:28:47 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 15:26:07 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "ft_termcap.h"
#include "../../libft/libft.h"
#include "movement.h"

int			update_vimarrow(int key, t_sh *shell)
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

static int	update_vimback(int key, t_sh *shell)
{
	char	is_symbol;

	if (shell->ix->x == 0)
		return (0);
	if (ft_isalnum(shell->input[shell->ix->y]->text[shell->ix->x]))
		is_symbol = 0;
	else
		is_symbol = 1;
	move_left(shell);
	if (key == 'B')
		while (shell->ix > 0 &&
						shell->input[shell->ix->y]->text[shell->ix->x] != ' ')
			move_left(shell);
	else if (is_symbol)
		while (shell->ix->x > 0 &&
					!ft_isalnum(shell->input[shell->ix->y]->text[shell->ix->x]))
			move_left(shell);
	else
		while (shell->ix->x > 0 &&
					ft_isalnum(shell->input[shell->ix->y]->text[shell->ix->x]))
			move_left(shell);
	if (shell->ix > 0 && shell->input[shell->ix->y]->text[shell->ix->x] == ' ')
		move_left(shell);
	return (0);
}

int			update_vimword(int key, t_sh *shell)
{
	char	is_symbol;

	if (ft_toupper(key) == 'B')
		return (update_vimback(key, shell));
	if ((int)shell->ix->x == shell->input[shell->ix->y]->len)
		return (0);
	is_symbol = !ft_isalnum(shell->input[shell->ix->y]->text[shell->ix->x]);
	move_right(shell);
	if (key == 'W')
		while ((int)shell->ix->x < shell->input[shell->ix->y]->len &&
					shell->input[shell->ix->y]->text[shell->ix->x] != ' ')
			move_right(shell);
	else if (is_symbol)
		while ((int)shell->ix->x < shell->input[shell->ix->y]->len &&
				!ft_isalnum(shell->input[shell->ix->y]->text[shell->ix->x]))
			move_right(shell);
	else
		while ((int)shell->ix->x < shell->input[shell->ix->y]->len &&
				ft_isalnum(shell->input[shell->ix->y]->text[shell->ix->x]))
			move_right(shell);
	if (shell->input[shell->ix->y]->text[shell->ix->x] == ' ')
		move_right(shell);
	return (0);
}
