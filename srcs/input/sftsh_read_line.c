/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/28 15:24:28 by sescolas         ###   ########.fr       */
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

void	reset_sess(t_sess *sess) 
{
	sess->cursor->x = ft_strlen(sess->prompt_str) + 1;
	sess->cursor->y = 0;
	sess->input_len = 0;
	sess->input_lines = 0;
	ft_strdel(&sess->input_text);
	sess->input_text = ft_strnew(BUFF_SIZE);
	sess->input_ix = 0;
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

/*
** Displays updated sesssion. Returns 0 on success.
*/
/*
static int render_keypress(int key, t_sess *sess)
{
	if (!key)
		return (0);
	if (ft_isprint(key))
		return (render(sess, 1));
	else if (IS_ARROWKEY(key))
		return (render(sess, 1));
	else if (key == KEY_HOME || key == KEY_END)
		return (render_home_end(key, sess));
	else if (key == KEY_BKSPC)
		return (render_bkspc());
	else if (key == KEY_DEL)
		return (render_del(sess));
	return (0); // this should probably actually be a 1
}
*/

/*
** Updates session based on pressed key.
*/
static int process_keypress(int key, t_sess *sess)
{
	if (sess->input_len > 0 && sess->input_len % BUFF_SIZE == 0)
		resize_buffer(&sess->input_text, sess->input_len);
	if (ft_isprint(key))
		return (update_printable(key, sess));
	else if (IS_ARROWKEY(key))
		return (update_arrowkey(key, sess));
	else if (key == KEY_HOME || key == KEY_END)
		return (update_home_end(key, sess));
	else if (key == KEY_BKSPC && sess->input_ix > 0)
		return (update_bkspc(sess));
	else if (key == KEY_DEL && sess->input_len > 0)
		return (update_del(sess));
	return (0);
	/*
	else
		write(1, &key, 1);

	return (0); // this shoulr probably really be a 1
*/
}

int		get_command_str(t_sess *sess)
{
	int key;

	reset_sess(sess);
	ft_padstr(sess->prompt_str, 1, sess->prompt_color);
	while ((key = get_keypress()) != KEY_ENTER)
	{
		if (!key)
			continue ;
		if (key == KEY_ESCAPE)
		{
			//if (enter_vim_mode(sess) != 0)
				return (1);
		}
		else if (key != '\0' && (render(sess, process_keypress(key, sess))) != 0)
			return (1);
		/*
		else if (process_keypress(key, sess) == 0)
		{
			if (render_keypress(key, sess) != 0)
				return (1);
		}
		*/
		//if (ft_keypress(key, sess) != 0)
		//	return (0);
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
