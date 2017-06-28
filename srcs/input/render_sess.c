/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:51:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/28 15:21:25 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"

static void	update_position(t_sess *sess, int cm)
{
	if (cm < 0 && (cm * -1) % sess->term_width == 0)
	{
		sess->cursor->y -= ((-1 * cm) / sess->term_width);
		return ;
	}
	else if (cm >= 0 && cm % sess->term_width == 0)
	{
		sess->cursor->y += cm / sess->term_width;
		return ;
	}
	if (cm > 0)
	{
		sess->cursor->y += ((sess->cursor->x + cm) / sess->term_width);
		sess->cursor->x = (sess->cursor->x + cm) % sess->term_width;
	}
	else
	{
		if ((int)sess->cursor->x + cm >= 0)
			sess->cursor->x = (int)sess->cursor->x + cm;
		else
		{
			sess->cursor->y = sess->cursor->y - 1 - ((int)((-1 * cm) / sess->term_width));
			sess->cursor->x = sess->term_width -
				((-1 * cm) % sess->term_width);
		}
	}
}

static void	clear_screen(int cm)
{
	int		ix;

	ix = -1;
	while (++ix < cm)
		ft_putchar(32);
	ix = -1;
	while (++ix <= cm)
		ft_putchar(8);
}

int		render(t_sess *sess, int cm)
{
	int		len;

	len = sess->input_len + ft_strlen(sess->prompt_str);
	ft_move_cursor(K_UP, sess->cursor->y);
	ft_move_cursor(K_LEFT, sess->cursor->x);
	ft_padstr(sess->prompt_str, 1, sess->prompt_color);
	ft_putstr(sess->input_text);
	if (cm < 0)
		clear_screen(cm * -1);
	ft_move_cursor(K_UP, len / sess->term_width);
//	ft_move_cursor(K_UP, sess->cursor->y);
	write(1, "\r", 1);
	update_position(sess, cm);
	ft_move_cursor(K_DOWN, sess->cursor->y);
	ft_move_cursor(K_RIGHT, sess->cursor->x);
	return (0);
}
/*
int		render_printable(t_sess *sess)
{
	int		len;
	int		ix;
	
	len = sess->input_len + ft_strlen(sess->prompt_str);
	ix = len;
	ft_move_cursor(K_UP, len / sess->term_width);
	write(1, "\r", 1);
	while (ix--)
		write(1, " ", 1);
	write(1, "\r", 1);
	ft_move_cursor(K_UP, len / sess->term_width);
	ft_padstr(sess->prompt_str, 1, sess->prompt_color);
	ft_putstr(sess->input_text);
	ft_move_cursor(K_UP, len / sess->term_width);
	write(1, "\r", 1);
	ft_move_cursor(K_DOWN, sess->cursor->x / sess->term_width);
	write(1, "\r", 1);
	ft_move_cursor(K_RIGHT, sess->cursor->x % sess->term_width);
	return (0);
}

void	clear_screen(t_sess *sess)
{
	int		len;
	int		i;

	len = ft_strlen(sess->prompt_str) + sess->input_len + 1;
	ft_move_cursor(K_UP, len / sess->term_width);
	i = len;
	while (i--)
		write(1, " ", 1);
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
*/
