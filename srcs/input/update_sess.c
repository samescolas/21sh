/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:11:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/25 11:36:31 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"

/*
** Direct memset because my memmove is terribly inefficient.
*/
int		update_printable(int key, t_sess *sess)
{
	char	*input;
	int		i;
	int		len;

	input = sess->input_text;
	if (sess->input_len == sess->cursor->x)
		input[sess->input_len] = key;
	else
	{
		len = ft_strlen(&input[sess->cursor->x]);
		i = -1;
		while (++i < len)
			ft_memset(&input[sess->input_len - i],
					input[sess->input_len - i - 1], 1);
		ft_memset(&input[sess->cursor->x], key, 1);
	}
	++(sess->input_len);
	++(sess->cursor->x);
	return (0);
}

int		update_bkspc(t_sess *sess)
{
	int		i;
	int		len;
	char	*input;

	input = sess->input_text;
	if (sess->input_len == sess->cursor->x)
	{
		input[sess->cursor->x - 1] = '\0';
	}
	else
	{
		len = ft_strlen(&input[sess->cursor->x]);
		i = -1;
		while (++i < len)
			ft_memset(&input[sess->cursor->x + i],
					input[sess->cursor->x + i + 1], 1);
		input[sess->cursor->x - 1] = '\0';
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

/*
** Need to update this to work for multiline stuff.
*/
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
	if (key == KEY_HOME)
		sess->cursor->x = 0;
	else
		sess->cursor->x = sess->input_len;
	return (0);
}
