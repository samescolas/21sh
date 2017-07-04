/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 10:42:14 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 18:22:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
#include "ft_keypress.h"
/*
int		ft_backspace(t_sess *sess)
{
	char	*line;
	int		len;

	line = sess->input_text;
	if (sess->input_len == sess->cursor->x)
	{
		line[--(sess->input_len)] = '\0';
		ft_arrowkeys(KEY_LEFT, sess);
		write(1, " ", 1);
		ft_move_cursor(K_LEFT, 1);
	}
	else 
	{
		len = ft_strlen(&line[sess->cursor->x]);
		ft_memmove(&line[sess->cursor->x - 1], &line[sess->cursor->x], len);
		line[--(sess->input_len)] = '\0';
		ft_move_cursor(K_LEFT, 1);
		write(1, &line[sess->cursor->x - 1], len);
		write(1, " ", 1);
		ft_move_cursor(K_LEFT, len);
		ft_arrowkeys(KEY_LEFT, sess);
	}
	return (0);
}

int		ft_arrowkeys(int c, t_sess *sess)
{
	if (c == KEY_UP)
	{
		//ft_move_cursor(KEY_UP, 1);
		//++(term->pos->y);
	}
	else if (c == KEY_DOWN)
	{
		//ft_move_cursor(KEY_DOWN, 1);
		//--(term->pos->y);
	}
	else if (c == KEY_RIGHT && sess->cursor->x < sess->input_len)
	{
		ft_move_cursor(K_RIGHT, 1);
		++(sess->cursor->x);
	}
	else if (c == KEY_LEFT && sess->cursor->x > 0)
	{
		ft_move_cursor(K_LEFT, 1);
		--(sess->cursor->x);
	}
	return (0);
}

int		ft_delete(char **line, t_term *term)
{
	int		len;

	if (term->cmd_len == term->pos->x)
		return (1);
	len = ft_strlen(&(*line)[term->pos->x + 1]);
	ft_memmove(&(*line)[term->pos->x], &(*line)[term->pos->x + 1], len);
	write(1, &(*line)[term->pos->x], len);
	write(1, " ", 1);
	(*line)[--(term->cmd_len)] = '\0';
	while (len-- >= 0)
		ft_move_cursor(KEY_LEFT, 1);
	return (1);
}
*/
/*
int ft_printable(char c, t_sess *sess)
{
	int		len;
	char	*line;

	line = sess->input_text;
	if (sess->input_len == 0 && c == ';')
		return (1);
	if (sess->input_len == sess->cursor->x)
	{
		write(1, &c, 1);
		line[(sess->input_len)++] = c;
		++(sess->cursor->x);
	}
	else
	{
		len = ft_strlen(&line[sess->cursor->x]);
		ft_memmove(&line[sess->cursor->x + 1], &line[sess->cursor->x], len);
		line[sess->cursor->x] = c;
		write(1, &line[sess->cursor->x], len + 1);
		ft_move_cursor(K_LEFT, len);
		++(sess->input_len);
		++(sess->cursor->x);
	}
	return (0);
}
*/
/*
int		ft_escape(char **line, t_term *term)
{
	int		ret;
	char	c;

	if ((ret = read(STDIN_FILENO, &c, 1)) > 0 && c == '[')
	{
		if ((ret = read(STDIN_FILENO, &c, 1)) > 0)
		{
			if (c >= 'A' && c <= 'D')
				ft_arrowkeys(c, term);
			else if (c == '3')
			{
				if (read(STDIN_FILENO, &c, 1) > 0 && c == '~')
					ft_delete(line, term);
			}
			else if (c == 'H')
				while (term->pos->x)
					ft_arrowkeys('D', term);
			else if (c == 'F')
				while (term->pos->x != term->cmd_len)
					ft_arrowkeys('C', term);
			else
				write(1, &c, 1);
		}
	}
	else
		return (enter_vim_mode(line, term));
	return (1);
}*/
