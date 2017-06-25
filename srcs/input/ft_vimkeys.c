/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vimkeys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 11:45:53 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/24 17:08:25 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "ft_keypress.h"
#include "ft_termcap.h"

/*
void		copy_paste_mode(char **line, t_term *term);
void		vim_paste(char **line, t_term *term);

static char	get_number(int *iterations)
{
	char	c;

	while (1742)
	{
		if (read(STDIN_FILENO, &c, 1) > 0)
		{
			if (c >= '0' && c <= '9')
			{
				(*iterations) *= 10;
				(*iterations) += (c - '0');
			}
			else
				return (c);
		}
	}
}

int			ft_vimkeypress(char c, char **line, t_term *term)
{
	if (c == 'h' || c == 'l')
		ft_arrowkeys(c, term);
	else if (c == 'v')
		copy_paste_mode(line, term);
	else if (c == 'p' && term->clipboard_len > 0)
		vim_paste(line, term);
	else if (c == 'w' || c == 'b')
	{
		ft_arrowkeys((c == 'w' ? 'l' : 'h'), term);
		while (term->pos->x < term->cmd_len && term->pos->x > 0 && \
				(*line)[term->pos->x - 1] != ' ')
			ft_arrowkeys((c == 'w' ? 'l' : 'h'), term);
	}
	else if (c == 'x')
		ft_delete(line, term);
	else if (c == 'r')
	{
		while (read(STDIN_FILENO, &c, 1) <= 0)
			continue ;
		write(1, &c, 1);
		(*line)[term->pos->x] = c;
		ft_move_cursor(KEY_LEFT, 1);
	}
	else if (c == 'A' || c == '$')
		while (term->cmd_len != term->pos->x)
			ft_arrowkeys('C', term);
	else if (c == 'I' || c == '0')
		while (term->pos->x > 0)
			ft_arrowkeys('D', term);
	return (c != 'I' && c != 'A');
}

int			ft_vimkeys(char c, char **line, t_term *term)
{
	int		iterations;

	iterations = 1;
	if (c == '\r' || c == 10)
		return (0);
	if (c >= '1' && c <= '9')
	{
		iterations = c - '0';
		c = get_number(&iterations);
	}
	while (iterations--)
		if (!ft_vimkeypress(c, line, term))
			return (0);
	return (1);
}
*/
int		enter_vim_mode(t_sess *sess)
{
	int		key;

	while (1742)
	{
		key = get_keypress();
		if (key == 'h')
			ft_arrowkeys(KEY_LEFT, sess);
		else if (key == 'l')
			ft_arrowkeys(KEY_RIGHT, sess);
		else if (key == KEY_ENTER)
			return (1);
	}
	return (0);
}
/*
int		enter_vim_mode(char **line, t_term *term)
{
	char	c;
	while (1742)
	{
		if (read(STDIN_FILENO, &c, 1) > 0)
		{
			if (c == '\r')
				return (0);
			if (c == 'i' || !ft_vimkeys(c, line, term))
				return (1);
		}
	}
	return (1);
}*/
