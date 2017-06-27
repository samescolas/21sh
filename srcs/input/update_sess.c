/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:11:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/26 12:38:56 by sescolas         ###   ########.fr       */
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

	if (sess->input_ix == (int)sess->input_len)
		sess->input_text[sess->input_ix] = (char)key;
	else
	{
		len = ft_strlen(&sess->input_text[sess->input_ix]);
		i = -1;
		while (++i < len)
			ft_memset(&sess->input_text[sess->input_ix - i],
					sess->input_text[sess->input_ix - i - 1], 1);
		ft_memset(&sess->input_text[sess->input_ix], (char)key, 1);
	}
	++(sess->input_ix);
	++(sess->input_len);
	return (0);
}
/*
int		update_printable(int key, t_sess *sess)
{
	char	*input;
	int		i;
	int		len;
	int		prompt_len;

	input = sess->input_text;
	prompt_len = ft_strlen(sess->prompt_str) + 1;
	if (sess->input_len + prompt_len == sess->cursor->x)
		input[sess->input_len] = key;
	else
	{
		len = ft_strlen(&input[sess->cursor->x - prompt_len]);
		i = -1;
		while (++i < len)
			ft_memset(&input[sess->input_len - i],
					input[sess->input_len - i - 1], 1);
		ft_memset(&input[sess->cursor->x - prompt_len], key, 1);
	}
	++(sess->input_len);
	++(sess->cursor->x);
	return (0);
}
*/
/*
int		update_bkspc(t_sess *sess)
{
	int		i;
	int		len;
	int		prompt_len;
	char	*input;

	input = sess->input_text;
	prompt_len = ft_strlen(sess->prompt_str) + 1;
	ft_move_cursor(K_LEFT, 1);
	write(1, " ", 1);
	if (sess->input_len + prompt_len  == sess->cursor->x)
		input[sess->cursor->x - 1 - prompt_len] = '\0';
	else
	{
		len = ft_strlen(&input[sess->cursor->x - prompt_len]);
		i = -1;
		while (++i < len)
			ft_memset(&input[sess->cursor->x + i - prompt_len],
					input[sess->cursor->x + i + 1 - prompt_len], 1);
		input[sess->cursor->x - 1 - prompt_len] = '\0';
	}
	--(sess->cursor->x);
	--(sess->input_len);
	return (0);
}

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
/*
int		update_arrowkey(int key, t_sess *sess)
{
	if (key == KEY_LEFT && sess->cursor->x > 0)
		--(sess->cursor->x);
	else if (key == KEY_RIGHT && sess->cursor->x < sess->input_len)
		++(sess->cursor->x);
	else if (key == KEY_UP)
	{

	}
	else if (key == KEY_DOWN)
	{
	}
	else
		return (1);
	return (0);
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
*/
