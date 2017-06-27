/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vim_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:28:47 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/26 12:21:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "ft_termcap.h"
#include "../../libft/libft.h"
/*
int		update_vimarrow(int key, t_sess *sess)
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

int		update_vimword(int key, t_sess *sess)
{
	if (ft_toupper(key) == 'W')
	{
		if (sess->cursor->x == sess->input_len)
			return (1);
		if (key == 'W')
			sess->cursor->x += ft_strfind(&sess->input_text[sess->cursor->x + 1], ' ');
		else
		{
			while (ft_isalpha(sess->input_text[sess->cursor->x]))
				++(sess->cursor->x);
		}
	}
	else if (ft_toupper(key) == 'B')
	{
		if (sess->cursor->x == 0)
			return (1);
		if (key == 'B')
		{
			while (sess->cursor->x > 0)
				if (ft_isalpha(sess->input_text[--(sess->cursor->x)]))
					break ;
		}
		else
		{
			while (sess->cursor->x > 0)
				if (sess->input_text[--(sess->cursor->x)] == ' ')
					break ;
		}
	}
	else
		return (1);
	return (0);
}
*/
