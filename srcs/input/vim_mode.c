/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:13:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 14:35:25 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"

static int	process_vimkey(int key, t_sh *shell)
{
	if (is_vimarrow(key))
		return (update_vimarrow(key, shell));
	else if (ft_toupper(key) == 'W' || ft_toupper(key) == 'B')
		return (update_vimword(key, shell));
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
		if (ft_isdigit(key) && ft_vimrepeat(key, shell) < 0)
			return (1);
		if (process_vimkey(key, shell) != 0)
			return (1);
	}
	return (key == KEY_ENTER);
}
