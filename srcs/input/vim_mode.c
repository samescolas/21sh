/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:13:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 15:33:12 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
#include "movement.h"

static int	process_vimkey(int key, t_sh *shell)
{
	if (is_vimarrow(key))
		return (update_vimarrow(key, shell));
	else if (ft_toupper(key) == 'W' || ft_toupper(key) == 'B')
		return (update_vimword(key, shell));
	else if (key == 'I' || key == '0')
	{
		while ((int)shell->ix->x > 0)
			move_left(shell);
		return (key == 'I');
	}
	else if (key == 'A' || key == '$')
	{
		while ((int)shell->ix->x < shell->input[shell->ix->y]->len)
			move_right(shell);
		return (key == 'A');
	}
	else if (key == 'r' && ft_isprint(key = get_keypress()))
	{
		update_del(shell);
		update_printable(key, shell);
		move_left(shell);
	}
	return (0);
}

static int	ft_vimrepeat(int key, t_sh *shell)
{
	int		times;
	int		success;

	success = 0;
	times = key - '0';
	while (ft_isdigit((key = get_keypress())))
		times = 10 * times + (key - '0');
	while (times--)
		success += process_vimkey(key, shell);
	return (success);
}

int			enter_vim_mode(t_sh *shell)
{
	int		key;

	while ((key = get_keypress()) != KEY_ENTER)
	{
		if (key == 'i')
			return (0);
		if (key == '\0')
			continue ;
		if (ft_isdigit(key) && key > '0' && ft_vimrepeat(key, shell) < 0)
			return (1);
		if (process_vimkey(key, shell) != 0)
			return (0);
	}
	return (key == KEY_ENTER);
}
