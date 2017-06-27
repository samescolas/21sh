/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_mode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:13:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/26 12:21:29 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
/*
static int	process_vimkey(int key, t_sess *sess)
{
	if (is_vimarrow(key))
		return (update_vimarrow(key, sess));
	else if (ft_toupper(key) == 'W' || ft_toupper(key) == 'B')
		return (update_vimword(key, sess));
	return (0);
}

static int	render_vimkey(int key, t_sess *sess)
{
	if (is_vimarrow(key))
		return (render_vimarrow(key));
	else if (ft_toupper(key) == 'W' || ft_toupper(key) == 'B')
		return (render_vimword(sess));
	return (sess != (void *)0);
}

int		enter_vim_mode(t_sess *sess)
{
	int		key;

	while ((key = get_keypress()) != KEY_ENTER)
	{
		if (key == '\0')
			continue ;
		if (process_vimkey(key, sess) == 0)
		{
			if (render_vimkey(key, sess) != 0)
				return (1);
		}
	}
	return (key == KEY_ENTER);
}
*/
