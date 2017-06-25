/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vim_copy_paste.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 08:08:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/23 10:18:51 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "ft_keypress.h"
#include "ft_termcap.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "sftsh_utils.h"
#include "sftsh_vars.h"
#include "../../libft/libft.h"

void	cpasta_move(char c, char **line, t_sess *sess, int *offset)
{
	char	to_print[2];

	to_print[0] = (*line)[sess->cursor->x];
	if ((*offset > 0 && c == 'h') || (*offset < 0 && c == 'l'))
		ft_putstr_mode(to_print, (void *)0);
	else
		ft_putstr_mode(to_print, MR);
	ft_arrowkeys(c, sess);
	ft_move_cursor(KEY_LEFT, 1);
	*offset += (c == 'l' ? 1 : -1);
}

static int	vim_yank(char *line, t_sess *sess, int offset)
{
	if (offset > 0)
		sess->clipboard_len = offset + 1;
	else
		sess->clipboard_len = (offset * -1) + 1;
	if (offset > 0)
		sess->clipboard = ft_strndup(&line[sess->cursor->x - offset], offset);
	else
		sess->clipboard = ft_strndup(&line[sess->cursor->x], sess->clipboard_len);
	return (1);
}

void	vim_paste(char **line, t_sess *sess)
{
	int		len;
	char	*ret;

	write(1, sess->clipboard, sess->clipboard_len);
	write(1, &(*line)[sess->cursor->x], ft_strlen(&(*line)[sess->cursor->x]));
	len = (sess->clipboard_len + sess->cmd_len) / BUFF_SIZE;
	len = (len == 0 ? 2 * BUFF_SIZE : (len + 1) * BUFF_SIZE);
	if (!(ret = ft_strnew(len)))
		ft_fatal("sftsh: err: out of memory\n");
	if (sess->cursor->x == sess->cmd_len && sess->cmd_len > 0)
		ft_strcpy(ret, *line);
	else if (sess->cmd_len > 0)
		ft_strncpy(ret, *line, sess->cursor->x);
	ft_strncat(ret, sess->clipboard, sess->clipboard_len);
	if (sess->cursor->x != sess->cmd_len)
	{
		ft_move_cursor(KEY_LEFT, sess->cmd_len - sess->cursor->x);
		ft_strcat(ret, &(*line)[sess->cursor->x]);
	}
	sess->cursor->x += sess->clipboard_len;
	sess->cmd_len += sess->clipboard_len;
	ft_strdel(line);
	*line = ret;
}

void	vim_cut(char *line, t_sess *sess, int offset)
{
	use the vim x hotkey thing len number of times?
}

void	copy_paste_mode(char **line, t_sess *sess)
{
	char	c;
	char	to_print[2];
	int		offset;

	to_print[1] = '\0';
	offset = 0;
	if (sess->cursor->x == sess->cmd_len)
		ft_arrowkeys('h', sess);
	while (1742)
	{
		if (read(STDIN_FILENO, &c, 1) > 0)
		{
			if (c == 'q')
				break ;
			if (c == 27)
			{
				//if (vim_copy_escape(line, len, pos))
					break ;
			}
			else if ((c == 'l' && sess->cursor->x + 1 < sess->cmd_len)  || (c == 'h' && sess->cursor->x > 0))
				cpasta_move(c, line, sess, &offset);
			else if (c == 'b' || c == 'w')
			{
				cpasta_move((c == 'b' ? 'h' : 'l'), line, sess, &offset);
				while (sess->cursor->x > 1 && sess->cursor->x + 1 < sess->cmd_len && (*line)[sess->cursor->x - 1] != ' ')
					cpasta_move((c == 'b' ? 'h' : 'l'), line, sess, &offset);
			}
			else if (c == 'y' && vim_yank(*line, sess, offset))
				break ;
			else if (c == 'x') && vim_cut(*line, sess, offset))
				break ;
		}
	}
	ft_move_cursor(KEY_LEFT, sess->cursor->x);
	write(1, *line, ft_strlen(*line));
	ft_move_cursor(KEY_LEFT, sess->cmd_len - sess->cursor->x);
}
*/
