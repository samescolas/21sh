/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/25 08:58:25 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_read_line.h"
#include "sftsh_vars.h"
#include "sftsh_types.h"
#include "ft_keypress.h"
#include "ft_termcap.h"

void		resize_buffer(char **line, size_t len)
{
	char	*tmp;

	tmp = ft_strnew(len + BUFF_SIZE);
	ft_strncpy(tmp, *line, len);
	ft_strdel(line);
	*line = tmp;
}

static int ft_keypress(int c, t_sess *sess)
{
	if (sess->input_len > 0 && sess->input_len % BUFF_SIZE == 0)
		resize_buffer(&sess->input_text, sess->input_len);
	if (ft_isprint(c))
		return (ft_printable(c, sess));
	else if (c == 127 && sess->input_len > 0)
		return (ft_backspace(sess));
	else if (c == 127)
		return (0);
	else if (IS_ARROWKEY(c))
		return (ft_arrowkeys(c, sess));
	else if (c == KEY_ESCAPE)
		return (enter_vim_mode(sess));
	else if (c == KEY_HOME)
		while (sess->cursor->x != 0)
			ft_arrowkeys(KEY_LEFT, sess);
	else if (c == KEY_END)
		while (sess->cursor->x < sess->input_len)
			ft_arrowkeys(KEY_RIGHT, sess);
	else
		write(1, &c, 1);
	return (0);
}

void	reset_sess(t_sess *sess) 
{
	sess->cursor->x = 0;
	sess->cursor->y = 0;
	sess->input_len = 0;
	sess->input_lines = 0;
	ft_strdel(&sess->input_text);
	sess->input_text = ft_strnew(BUFF_SIZE);
}

/*
static int	read_line(t_sess *sess)
{
	char			buf;

	while (1742)
	{
		if (sess->cmd_len > BUFF_SIZE - 1 && sess->cmd_len % BUFF_SIZE == 0)
			resize_buffer(&sess->prompt[0], sess);
		if (read(STDIN_FILENO, &buf, 1) > 0 && buf != '\r')
		{
			if (!ft_keypress(buf, sess))
				break ;
		}
		else if (buf == '\r')
			break ;
	}
	write(1, "\n", 1);
	return ((sess->cmd_len > 0 || *(sess->prompt[0]) != '\0') ? 1 : -1);
}
*/

int		get_command_str(t_sess*sess)
{
	int key;

	reset_sess(sess);
	while ((key = get_keypress()) != KEY_ENTER)
	{
		if (ft_keypress(key, sess) != 0)
			return (0);
	}
	return (0);
	/*
	int				line_read;

	ft_strdel(&(sess->prompt[0]));
	ft_padstr((sess->prompt[1] ? sess->prompt[1] : DEFAULT_PROMPT)\
			, 1, (sess->prompt[2] ? sess->prompt[2] : DEFAULT_COLOR));
	line_read = read_line(reset_sess(sess));
	while (line_read <= 0)
	{
		ft_strdel(&(sess->prompt[0]));
		ft_padstr((sess->prompt[1] ? sess->prompt[1] : DEFAULT_PROMPT)\
			, 1, (sess->prompt[2] ? sess->prompt[2] : DEFAULT_COLOR));
		line_read = read_line(reset_sess(sess));
	}
	return (1);
	*/
}
