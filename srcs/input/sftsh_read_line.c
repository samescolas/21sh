/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 17:53:52 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_read_line.h"
#include "sftsh_vars.h"
#include "sftsh_types.h"
#include "ft_keypress.h"
#include "ft_termcap.h"

void		resize_buffer(t_string *str)
{
	char	*tmp;

	tmp = ft_strnew(str->len + BUFF_SIZE);
	ft_strncpy(tmp, *line, len);
	ft_strdel(&str->text);
	str->text = tmp;
}

void		resize_input(t_sess *sess)
{
	char	**tmp;
	int		i;

	if (!(tmp = (t_string **)malloc(
			(sess->num_lines + BUFF_LINES) * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < sess->num_lines)
		tmp[i] = sess->input_text[i];
	tmp[i] = create_str(ft_strnew(BUFF_SIZE));
	free(sess->input_text);
	sess->input_text = tmp;
}

void	reset_sess(t_sess *sess) 
{
	int		i;

	i = -1;
	while (++i < sess->num_lines)
		ft_strdel(&sess->input_text[i]);
	free(sess->input_text);
	if (!(sess->input_text = (char **)malloc((BUFF_LINES + 1) * sizeof(char *))))
		ft_fatal("err: out of memory\n");
	sess->input_text[0] = create_str(ft_strnew(BUFF_SIZE));
	sess->input_ix = 0;
	sess->input_line = 0;
	sess->num_lines = 1;
	sess->input_len = 0;
	sess->cursor->x = ft_strlen(sess->prompt_str) + 1;
	sess->cursor->y = 0;
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
** Updates session based on pressed key.
*/
static int process_keypress(int key, t_sess *sess)
{
	if (sess->input_text[sess->input_line]->len > 0 &&
			sess->input_text[sess->input_line]->len % BUFF_SIZE == 0)
		resize_buffer(sess->input_text[sess->input_line]);
	//if (sess->input_len > 0 && sess->input_len % BUFF_SIZE == 0)
	//	resize_buffer(&sess->input_text, sess->input_len);
	if (ft_isprint(key) && key != KEY_ENTER)
		return (update_printable(key, sess));
	return (0);
	/*
	else if (IS_ARROWKEY(key))
		return (update_arrowkey(key, sess));
	else if (key == KEY_HOME || key == KEY_END)
		return (update_home_end(key, sess));
	else if (key == KEY_BKSPC && sess->input_ix > 0)
		return (update_bkspc(sess));
	else if (key == KEY_DEL && sess->input_len > 0)
		return (update_del(sess));
	else if (key == KEY_ENTER)
		return (update_printable('\n', sess));
	else
		write(1, &key, 1);
	return (0);
	*/
}

int		get_command_str(t_sess *sess)
{
	int key;

	reset_sess(sess);
	ft_padstr(sess->prompt_str, 1, sess->prompt_color);
	while ((key = get_keypress()) != '~')
	{
		if (!key)
			continue ;
		if (key == KEY_ESCAPE)
		{
			//if (enter_vim_mode(sess) != 0)
				return (1);
		}
		else if (key == KEY_ENTER ) //&& valid_brackets(sess->input_text) == 1 && valid_quotes(sess->input_text) == 1)
				break ;
		else if (key != '\0' && render(sess, process_keypress(key, sess)) != 0)
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
