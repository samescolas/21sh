/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:51:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/25 11:38:13 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"

int		render_printable(t_sess *sess)
{
	ft_move_cursor(K_LEFT, sess->cursor->x + 1);
	write(1, sess->input_text, sess->input_len);
	ft_move_cursor(K_LEFT, sess->input_len - sess->cursor->x);
	return (0);
}

int		render_arrowkey(int key)
{
	if (key == KEY_LEFT)
		ft_move_cursor(K_LEFT, 1);
	else if (key == KEY_RIGHT)
		ft_move_cursor(K_RIGHT, 1);
	else if (key == KEY_UP)
		return (0);
	else if (key == KEY_DOWN)
		return (0);
	return (0);
}

int		render_home_end(int key, t_sess *sess)
{
	if (key == KEY_HOME)
		write(1, "\r", 1);
	else
	{
		write(1, "\r", 1);
		ft_move_cursor(K_RIGHT, sess->cursor->x);
	}
	return (0);
}

int		render_bkspc(void)
{
	ft_move_cursor(K_LEFT, 1);
	write(1, " ", 1);
	ft_move_cursor(K_LEFT, 1);
	return (0);
}

int		render_del(t_sess *sess)
{
	ft_move_cursor(K_LEFT, 1);
	write(1, " ", 1);
	write(1, "\r", 1);
	write(1, sess->input_text, sess->input_len);
	write(1, " ", 1);
	ft_move_cursor(K_LEFT, sess->input_len - sess->cursor->x + 1);
	return (0);
}
