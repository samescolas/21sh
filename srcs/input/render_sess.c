/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:51:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/05 16:15:14 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"

static void	clear_screen(int cm)
{
	int		counter;

	counter = -10;
	while (++counter < cm)
		ft_putchar(32);
	counter = -10;
	while (++counter < cm)
		ft_putchar(8);
}

static void update_disp(t_sess *sess, int cm)
{
	if (cm > 0)
	{
		if ((int)sess->cursor->x == sess->term_width - 1)
		{
			ft_move_cursor(K_DOWN, 1);
			write(1, "\r", 1);
			sess->cursor->x = 0;
			sess->cursor->y += 1;
		}
		else
			sess->cursor->x += 1;
	}
	else if (cm < 0)
	{
		if (sess->cursor->x == 0)
		{
			ft_move_cursor(K_DOWN, 1);
			write(1, "\r", 1);
			sess->cursor->y -= 1;
			sess->cursor->x = sess->term_width - 1;
		}
		else
			sess->cursor->x -= 1;
	}

}

static int	get_y_offset(t_sess *sess)
{
	int		ix;
	int		ret;

	ix = -1;
	ret = 0;
	while (++ix < sess->input_line)
	{
		if (!ix)
			ret += (int)((sess->input_text[ix]->len + sess->prompt_str->len + 1) /
				sess->term_width);
		else
			ret += (int)(sess->input_text[ix]->len / sess->term_width);
	}
	if (sess->input_line > 0)
		ret += (int)((sess->input_text[ix]->len - sess->input_ix) / sess->term_width);
	else
		ret += (int)((sess->input_text[ix]->len - sess->input_ix +
			sess->prompt_str->len + 1) / sess->term_width);
	return (ret);
}

static int	get_x_offset(t_sess *sess)
{
	if (sess->input_line == 0)
		return ((sess->input_ix + sess->prompt_str->len + 1) % sess->term_width);
	return ((sess->input_ix) % sess->term_width);
}

int		render(t_sess *sess, int cm)
{
	t_string	*cmd;

	if (sess->num_lines > 1)
		cmd = join_strs(sess->input_text, sess->num_lines, '\n');
	else 
		cmd = create_str(ft_strdup(sess->input_text[0]->text));

	ft_move_cursor(K_UP, sess->cursor->y);
	write(1, "\r", 1);

	ft_padstr(sess->prompt_str->text, 1, sess->prompt_color->text);
	ft_putstr(cmd->text);

	clear_screen(cm);

	ft_move_cursor(K_UP, get_y_offset(sess));
	write(1, "\r", 1);
	ft_move_cursor(K_RIGHT, get_x_offset(sess));

	update_disp(sess, cm);
	return (0);
}
