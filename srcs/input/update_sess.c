/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:11:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/28 17:07:35 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
#include "ft_termcap.h"

/*
** Direct memset because my memmove is terribly inefficient.
*/
int		update_printable(int key, t_sess *sess)
{
	int	len;
	int	i;

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
		i = -1;
		while (++i < len)
			ft_memset(&sess->input_text[sess->input_len - i],
					sess->input_text[sess->input_len - i - 1], 1);
		ft_memset(&sess->input_text[sess->input_ix], (char)key, 1);
	}
	++(sess->input_ix);
	++(sess->input_len);
	return (1);
}

int		update_bkspc(t_sess *sess)
{
	int		len;
	int		i;

	if (sess->input_text[sess->input_len - 1] == '\n')
		--(sess->input_lines);
	if (sess->input_len == 0)
		return (0);
	if (sess->input_ix == (int)sess->input_len)
		sess->input_text[sess->input_ix - 1] = '\0';
	else
	{
		i = -1;
		len = ft_strlen(&sess->input_text[sess->input_ix]);
		while (++i < len)
			ft_memset(&sess->input_text[sess->input_ix + i - 1],
				sess->input_text[sess->input_ix + i], 1);
		sess->input_text[sess->input_len - 1] = '\0';
	}
	--(sess->input_len);
	--(sess->input_ix);
	return (-1);
}

int		update_del(t_sess *sess)
{
	int		i;
	int		len;

	if (sess->input_text[sess->input_ix] == '\n')
		--(sess->input_lines);
	if (sess->input_ix == (int)sess->input_len)
		return (0);
	len = ft_strlen(&sess->input_text[sess->input_ix]);
	i = -1;
	while (++i < len)
		ft_memset(&sess->input_text[sess->input_ix + i],
				sess->input_text[sess->input_ix + i + 1], 1);
	sess->input_text[sess->input_len - 1] = '\0';
	--(sess->input_len);
	return (0);
}

/*
int		update_del(t_sess *sess)
{
	int		len;
	int		i;
	char	*input;

	if (sess->cursor->x == sess->input_len)
		return (1);
	input = sess->input_text;
	len = sess->input_len - sess->cursor->x - 1;
	i = -1;
	while (++i < len)
		ft_memset(&input[sess->cursor->x + i],
				input[sess->cursor->x + i + 1], 1);
	input[sess->input_len - 1] = '\0';
	--(sess->input_len);
	return (0);
}
*/

/*
** Need to update this to work for multiline stuff.
*/
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
/*
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
*/

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
