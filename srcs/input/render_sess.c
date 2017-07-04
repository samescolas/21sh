/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:51:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 16:18:03 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
/*
static int get_line_length(t_sess *sess)
{
	char	*start;
	char	*end;

	//if (sess->input_text[sess->input_ix - 1] == '\n' || (sess->cursor->y == 0 &&
	//	sess->input_len + ft_strlen(sess->prompt_str) == sess->term_width))
	//	return (0);
	//ft_putstr("in get_line_length with string ");
	//ft_putendl(sess->input_text);
	if (!(start = ft_strrchr(&sess->input_text[sess->input_ix], '\n')))
	{
		//ft_putstr("no newline");
		start = sess->input_text;
		if (ft_strlen(start) + ft_strlen(sess->prompt_str) + 1 >= sess->term_width && ft_strlen(start) <= sess->term_width)
			return ((sess->term_width - ft_strlen(start)));
		//	return (0);
	}
	//ft_putstr("\nstart: ");
	//ft_putendl(start);
	if ((end = ft_strchr(start, '\n')))
	{
		//write(1, "found an ending newline", 4);
		return ((int)(end - start));
	}
	//ft_putstr("end: ");
	//ft_putendl(end);
	return (ft_strlen(start)); 
}

static void	update_position2(t_sess *sess, int cm)
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
		sess->cursor->y += ((sess->cursor->x + cm) / sess->term_width); // + sess->input_lines ?
		if (sess->input_lines > 1)
			sess->cursor->x = (ft_strlen(sess->prompt_str) + sess->input_len + 1)  % sess->term_width;
		else 
			sess->cursor->x = ((get_line_length(sess) + ft_strlen(sess->prompt_str) + 1)  % sess->term_width);
		//sess->cursor->y += ((sess->cursor->x + cm) / sess->term_width); // + sess->input_lines ?
		//sess->cursor->x = ((get_line_length(sess) + ft_strlen(sess->prompt_str) + 1)  % sess->term_width);
		sess->cursor->y += ((sess->cursor->x + cm) / sess->term_width); // + sess->input_lines ?
		//ft_putstr("moving cursor to ");
		//ft_putnbr(get_line_length(sess));
		//ft_putstr(" .\n");
		sess->cursor->x = (get_line_length(sess) % sess->term_width);
		if (sess->cursor->y == 0)
			sess->cursor->x = ((ft_strlen(sess->prompt_str) + 1) + sess->cursor->x) % sess->term_width;
		//sess->cursor->x = (sess->cursor->x + cm) % sess->term_width;
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
*/
static void move_left(t_sess *sess, int n)
{
	n *= -1;
	while (n--)
	{
		if (sess->cursor->x == 0)
		{
			sess->cursor->y -= 1;
			sess->cursor->x = sess->term_width - 1;
		}
		else
			sess->cursor->x -= 1;
	}
}

static void	move_right(t_sess *sess, int n)
{
	while (n--)
	{
		if (sess->cursor->x == sess->term_width - 1)
		{
			sess->cursor->x = 0;
			sess->cursor->y += 1;
		}
		else
			sess->cursor->x += 1;
	}
}
/*
static void	snapback(t_sess *sess)
{
	int		ix;
	int		curr_line;
	char	*start;
	char	*end;

	if (sess->input_text[sess->input_ix - 1] == '\n')
		sess->cursor->x = 0;
	else if (sess->input_lines > 0)
	{
		curr_line = 0;
		ix = -1;
		start = sess->input_text;
		while (++ix < sess->input_ix - 1)
			if (sess->input_text[ix] == '\n')
				start = &sess->input_text[ix];
		if (!(end = ft_strchr(start, '\n')))
			sess->cursor->x = ft_strlen(start) % sess->term_width;
		sess->cursor->x = ((int)(end - start) / (int)sizeof(char)) % (int)sess->term_width;
	}
}
*/
static void	update_position(t_sess *sess, int cm)
{
	if (cm > 0)
		move_right(sess, cm);
	else
		move_left(sess, cm);
//	snapback(sess);
}

static void	clear_screen(int cm)
{
	int		ix;

	ix = -10;
	while (++ix < cm)
		ft_putchar(32);
	ix = -10;
	while (++ix <= cm)
		ft_putchar(8);
}

static int	redraw(t_sess *sess, int cm)
{
	int		lines;
	int		len;
	int		i;

	ft_move_cursor(K_UP, sess->cursor->y);
	write(1, "\r", 1);
	ft_padstr(sess->prompt_str, 1, sess->prompt_color);
	len = ft_strlen(sess->prompt_str);
	lines = 0;
	i = -1;
	while (sess->input_text[++i])
	{
		write(1, &sess->input_text[i], 1);
		if (++len == (int)sess->term_width || sess->input_text[i] == '\n')
		{
			len = 0;
			++lines;
		}
	}
	if (cm <= 0)
		clear_screen(cm * -1);
	return (lines);
}

int		render(t_sess *sess, int cm)
{
	int		len;

	len = redraw(sess, cm);
	ft_move_cursor(K_UP, len);
	write(1, "\r", 1);
	update_position(sess, cm);
	ft_move_cursor(K_DOWN, sess->cursor->y);
	//len = ft_strrchr(sess->input_text, '\0') - ft_strrchr(sess->input_text, '\n') - 1;
	//if (len < (int)sess->term_width && len >= 0)
	//	sess->cursor->x = len;
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
