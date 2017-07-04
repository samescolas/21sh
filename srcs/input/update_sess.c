/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:11:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 18:52:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
#include "ft_termcap.h"

int			update_printable(int key, t_sess *sess)
{
	if (sess->input_ix == sess->input_text[sess->input_line]->len)
		sess->input_text[sess->input_line]->text[(sess->input_ix)++] = (char)key;
	else
	{
		ft_memmove(&sess->input_text[sess->input_line]->text[sess->input_ix + 1],
			&sess->input_text[sess->input_line]->text[sess->input_ix], 1);
		sess->input_text[sess->input_line]->text[(sess->input_ix)++] = (char)key;
	}
	++(sess->input_text[sess->input_line]->len);
	++(sess->input_len);
	return (1);
}

/*int		update_printable(int key, t_sess *sess)
{
	int	len;

	if (key == 'p')
	{
		ft_putstr("(");
		ft_putnbr(sess->cursor->x);
		ft_putstr(", ");
		ft_putnbr(sess->cursor->y);
		ft_putstr(", ");
		ft_putnbr(sess->input_lines);
		ft_putstr(")\n");
		exit(1);
	}
	if (key == '\n')
	{
		++(sess->input_lines);
		sess->input_text[(sess->input_ix)++] = '\n';
		++(sess->input_len);
		if (sess->cursor->y == 0)
			return (sess->term_width - ft_strlen(sess->prompt_str) - sess->input_len);
		return (sess->term_width);
	}
	if (sess->input_ix == (int)sess->input_len)
		sess->input_text[sess->input_ix] = (char)key;
	else
	{
		len = ft_strlen(&(sess->input_text[sess->input_ix]));
		ft_memmove(&sess->input_text[sess->input_ix + 1], &sess->input_text[sess->input_ix], len);
		ft_memset(&sess->input_text[sess->input_ix], (char)key, 1);
	}
	++(sess->input_ix);
	++(sess->input_len);
	return (1);
}

int		update_bkspc(t_sess *sess)
{
	int		len;

	if (sess->input_text[sess->input_len - 1] == '\n')
		--(sess->input_lines);
	if (sess->input_len == 0)
		return (0);
	if (sess->input_ix == (int)sess->input_len)
		sess->input_text[sess->input_ix - 1] = '\0';
	else
	{
		len = ft_strlen(&sess->input_text[sess->input_ix]);
		ft_memmove(&sess->input_text[sess->input_ix], &sess->input_text[sess->input_ix + 1], len);
		if (sess->input_text[sess->input_len - 1] == '\n')
			--sess->input_lines;
		sess->input_text[sess->input_len - 1] = '\0';
	}
	--(sess->input_len);
	--(sess->input_ix);
	return (-1);
}

int		update_del(t_sess *sess)
{
	int		len;

	if (sess->input_text[sess->input_ix] == '\n')
		--(sess->input_lines);
	if (sess->input_ix == (int)sess->input_len)
		return (0);
	len = ft_strlen(&sess->input_text[sess->input_ix]);
	ft_memmove(&sess->input_text[sess->input_ix], &sess->input_text[sess->input_ix + 1], len);
	sess->input_text[sess->input_len - 1] = '\0';
	--(sess->input_len);
	return (0);
}
*/

int		update_arrowkey(int key, t_sess *sess)
{
	int	ret;

	ret = 0;
	if (key == KEY_LEFT && (sess->input_line > 0 || sess->input_ix > 0))
	{
		if (sess->input_ix == 0)
			sess->input_ix = sess->input_text[--(sess->input_line)]->len;
		else
			sess->input_ix -= 1;
		ret = -1;
	}
	else if (key == KEY_RIGHT && (sess->input_line + 1 < sess->num_lines ||
			sess->input_ix < sess->input_text[sess->input_line]->len))
	{
		if (sess->input_ix == sess->input_text[sess->input_line]->len)
		{
			sess->input_ix = 0;
			sess->input_line -= 1;
		}
		else
			sess->input_ix += 1;
		ret = 1;
	}
	else if (key == KEY_UP && sess->input_line > 0)
	{
		if (sess->input_text[--(sess->input_line)]->len < sess->input_ix)
			sess->input_ix = sess->input_text[sess->input_line]->len;
		ret = sess->term_width * -1;
	}
	else if (key == KEY_DOWN && (sess->input_line < sess->num_lines))
	{
		if (sess->input_text[++(sess->input_line)]->len < sess->input_ix)
			sess->input_ix = sess->input_text[sess->input_line]->len;
		ret = sess->term_width;
	}
	return  (ret);
}

/*
int		update_arrowkey(int key, t_sess *sess)
{
	int		len;
	int		num_lines;
	int		ret;

	len = ft_strlen(sess->prompt_str) + 1 + sess->input_len;
	num_lines = len / sess->term_width;
	ret = 0;
	if (key == KEY_LEFT && ((sess->cursor->y == 0 && sess->cursor->x >
		ft_strlen(sess->prompt_str) + 1) || sess->cursor->y > 0))
		ret = -1;
	else if (key == KEY_RIGHT && ((int)sess->cursor->y != num_lines ||
			sess->cursor->x < len % sess->term_width))
		ret = 1;
	else if (key == KEY_UP && sess->cursor->y > 0)
		ret = -1 * (int)sess->term_width;
	else if (key == KEY_DOWN && (int)sess->cursor->y < num_lines)
	{
		if ((int)sess->cursor->y + 1 == num_lines && sess->cursor->x > len % sess->term_width)
		{
			sess->input_ix = sess->input_len;
			return (sess->term_width - sess->cursor->x + (len % sess->term_width));
		}
		ret = sess->term_width;
	}
	sess->input_ix += ret;
	return (ret);
}

int		update_home_end(int key, t_sess *sess)
{
	int		len;

	len = ft_strlen(sess->prompt_str) + 1;
	if (key == KEY_HOME)
		sess->cursor->x = len;
	else
		sess->cursor->x = sess->input_len + len;
	return (0);
}

int		update_home_end(int key, t_sess *sess)
{
	int		len;

	len = ft_strlen(sess->prompt_str) + sess->input_len + 1;
	if (key == KEY_HOME)
	{
		sess->input_ix = 0;
		render(sess, sess->term_width * sess->cursor->y * -1);
		return (sess->cursor->x * -1 + ft_strlen(sess->prompt_str) + 1);
	}
	else
	{
		sess->input_ix = sess->input_len - 1;
		render(sess, sess->term_width * ((len / sess->term_width) - sess->cursor->y));
		if (len % sess->term_width == 1)
			return (sess->cursor->x - ft_strlen(sess->prompt_str) - 1);
		return (sess->cursor->x);
	}
}
*/
