/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/05 11:17:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_read_line.h"
#include "sftsh_utils.h"
#include "sftsh_vars.h"
#include "sftsh_types.h"
#include "ft_keypress.h"
#include "ft_termcap.h"

void		resize_input(t_sess *sess)
{
	t_string	**tmp;
	int			i;

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
		ft_strdel(&sess->input_text[i]->text);
	free(sess->input_text);
	if (!(sess->input_text = (t_string **)malloc((BUFF_LINES + 1) * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	sess->input_text[0] = create_str(ft_strnew(BUFF_SIZE));
	sess->input_ix = 0;
	sess->input_line = 0;
	sess->num_lines = 1;
	sess->input_len = 0;
	sess->cursor->x = sess->prompt_str->len + 1;
	sess->cursor->y = 0;
}

static int	update_newline(t_sess *sess)
{
	if (sess->num_lines % BUFF_LINES == 0)
		resize_input(sess);
	sess->input_text[++(sess->input_line)] = create_str(ft_strnew(BUFF_SIZE));
	sess->input_ix = 0;
	sess->num_lines += 1;
	return (sess->term_width - sess->cursor->x);
}

/*
** Updates session based on pressed key.
*/
static int process_keypress(int key, t_sess *sess)
{
	if (ft_isprint(key) && key != KEY_ENTER)
		return (update_printable(key, sess));
	else if (IS_ARROWKEY(key))
		return (update_arrowkey(key, sess));
	//else if (key == KEY_HOME || key == KEY_END)
	//	return (update_home_end(key, sess));
	else if (key == KEY_BKSPC && sess->input_ix > 0)
		return (update_bkspc(sess));
	else if (key == KEY_DEL && sess->input_len > 0)
		return (update_del(sess));
	else if (key == KEY_ENTER)
		return (update_newline(sess));
	return (0);
	/*
	else
		write(1, &key, 1);
	return (0);
	*/
}

int		get_command_str(t_sess *sess)
{
	int key;

	reset_sess(sess);
	ft_padstr(sess->prompt_str->text, 1, sess->prompt_color->text);
	while ((key = get_keypress()) != '~')
	{
		if (!key)
			continue ;
		if (key == KEY_ESCAPE)
		{
			//if (enter_vim_mode(sess) != 0)
				return (1);
		}
		else if (key == KEY_ENTER && valid_brackets(sess->input_text, sess->num_lines) == 1 && valid_quotes(sess->input_text, sess->num_lines) == 1)
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
