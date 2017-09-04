/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sess.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 09:11:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 19:54:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"
#include "ft_termcap.h"
#include "movement.h"
#include "sftsh_utils.h"

/*
** Function to write a printable character to the terminal,
** update session info, and move the cursor appropriately.
** If the cursor is not at the end of the line, the remainder
** of the line must be shifted to the right.
*/
int			update_printable(int key, t_sh *shell)
{
	insert_str(shell->input[shell->ix->y], (char)key, (shell->ix->x)++);
	write(1, &key, 1);
	shell->curr->x += 1;
	if (shell->curr->x == shell->term->x)
	{
		shell->curr->x = 0;
		shell->curr->y += 1;
		write(1, "\r\n", 2);
	}
	if ((int)shell->ix->y == 0 && shell->ix->x < get_term_width())
		write_return(&shell->input[shell->ix->y]->text[shell->ix->x], shell->curr, 0);
	else if ((int)shell->ix->x != shell->input[shell->ix->y]->len)
		write_arr_return(&shell->input[shell->ix->y], shell->curr, shell->lines - shell->ix->y);
		//write_return(&shell->input[shell->ix->y]->text[shell->ix->x], shell->curr, 0);
	return (0);
}

/*
** To backspace we write over the current character and remove it from input.
*/

int			update_bkspc(t_sh *shell)
{
	if (shell->ix->x > 0)
	{
		if (shell->curr->x > 0)
		{
			ft_move_cursor(K_LEFT, 1);
			write(1, " ", 1);
		}
		else
		{
			ft_move_cursor(K_UP, 1);
			write(1, "\r", 1);
			ft_move_cursor(K_RIGHT, shell->term->x - 1);
			write(1, " \r\n", 3);
		}
		move_left(shell);
		remove_str(shell->input[shell->ix->y], shell->ix->x);
		if ((int)shell->ix->x < shell->input[shell->ix->y]->len)
			write_return(&shell->input[shell->ix->y]->text[shell->ix->x], shell->curr, 1);
	}
	else if (shell->ix->y > 0 && shell->input[shell->ix->y]->len == 0)
	{
		remove_strarr(&shell->input, shell->ix->y, (shell->lines)--);
		move_left(shell);
		if (shell->ix->y + 1 < shell->lines)
		{
			write(1, "\n", 1);
			write_arr_return(&shell->input[shell->ix->y + 1], shell->curr, shell->lines - shell->ix->y - 1);
		}
		else
		{
			write(1, "\n", 1);
			clear_line(get_term_width());
			ft_write_loc((void *)0, *(shell->curr));
		}
	}
	return (0);
}

int			update_del(t_sh *shell)
{
	int		i;

	if (shell->input[shell->ix->y]->len > 1)
	{
		remove_str(shell->input[shell->ix->y], shell->ix->x);
		write_return(&shell->input[shell->ix->y]->text[shell->ix->x], shell->curr, 1);
	}
	else if (shell->lines > 0)
	{
		remove_strarr(&shell->input, shell->ix->y, (shell->lines)--);
		if (shell->ix->y == shell->lines)
			move_left(shell);
		i = shell->ix->y - 1;
		while (++i < (int)shell->lines)
		{
			write(1, shell->input[i]->text, shell->input[i]->len);
			write(1, "\n", 1);
		}
		clear_line(shell->term->x);
		ft_write_loc((void *)0, *shell->curr);
	}
	return (0);
}

int			update_arrowkey(int key, t_sh *shell)
{
	int		i;
	t_list	*tmp;

	i = 0;
	if (key == KEY_UP || key == KEY_DOWN)
	{
		update_shell_history(shell);
		while (1742)
		{
			write(1, "looping\n", 8);
			if (!IS_ARROWKEY((key = get_keypress())))
				break ;
			++i;
			tmp = shell->history;
			if (key == KEY_UP)
				tmp = tmp->next;
			else if (key == KEY_DOWN)
				tmp = tmp->prev;
			else
				break ;
			ft_write_loc((void *)0, *shell->strt);
			ft_padstr(shell->prompt[0]->text, 1, shell->prompt[1]->text);
			write(1, tmp->str->text, tmp->str->len);
		}
	}
	if (key == KEY_LEFT)
		move_left(shell);
	else if (key == KEY_RIGHT)
		move_right(shell);
	else
		return (process_keypress(key, shell));
	return (0);
}

int			update_newline(t_sh *shell)
{
	int		i;

	if (shell->lines && shell->lines % BUFF_LINES == 0)
	 	resize_input(&shell->input, shell->lines);
	if (shell->ix->y + 1 == shell->lines)
	{
		shell->input[shell->ix->y + 1] = create_str(ft_strnew(BUFF_SIZE));
	}
	else
	{
		insert_strarr(&shell->input, create_str(ft_strnew(BUFF_SIZE)), shell->ix->y + 1, shell->lines);
		i = shell->ix->y - 1;
		while (++i < (int)shell->lines)
		{
			write(1, shell->input[i]->text, shell->input[i]->len);
			write(1, "\n", 1);
		}
		clear_line(shell->term->x);
		ft_write_loc((void *)0, *shell->curr);
	}
	shell->lines += 1;
	shell->ix->y += 1;
	shell->curr->y += 1;
	shell->ix->x = 0;
	shell->curr->x = 0;
	write(1, "\n", 1);
	return (0);
}

/*
int			update_newline(t_sh *shell)
{
	if (++(shell->lines) % BUFF_LINES == 0)
	{
		write(1, "ere", 1);
		resize_input(&shell->input, shell->lines);
	}
	else
	{
		write(1, "h", 1);
		shell->input[shell->ix->y + 1] = create_str(ft_strnew(BUFF_SIZE));
		write(1, "a", 1);
	}
	shell->ix->y += 1;
	shell->ix->x = 0;
	shell->curr->x = 0;
	shell->curr->y += 1;
	write(1, "\n\r", 2);
	return (0);
}
*/

int			update_home(t_sh *shell)
{
	if ((int)shell->ix->x == 0)
	{

		ft_write_loc((void *)0, *shell->strt);
		ft_move_cursor(K_RIGHT, shell->prompt[0]->len + 1);
		shell->ix->x = 0;
		shell->ix->y = 0;
		shell->curr->x = shell->strt->x;
		shell->curr->y = shell->strt->y + shell->prompt[0]->len + 1;
		//while ((int)shell->ix->y > 0)
		//{
			////ft_move_cursor(K_UP, 1);
			////write(1, "\r", 1);
			//wrap_left(shell);
			//shell->ix->y -= 1;
			//shell->ix->x = shell->input[shell->ix->y]->len;
			////shell->curr->x = shell->term->x - 1;
			////shell->curr->y -= 1;
			//while ((int)shell->ix->x > 0)
				//move_left(shell);
		//}
	}
	else
	{
		while ((int)shell->ix->x > 0)
			move_left(shell);
	}
	return (0);
}

int			update_end(t_sh *shell)
{
	if ((int)shell->ix->x == shell->input[shell->ix->y]->len)
	{
		while (shell->ix->y != shell->lines - 1)
		{
			ft_move_cursor(K_DOWN, 1);
			write(1, "\r", 1);
			shell->ix->y += 1;
			shell->ix->x = 0;
			shell->curr->x = 0;
			shell->curr->y += 1;
			while ((int)shell->ix->x != shell->input[shell->ix->y]->len)
				move_right(shell);
		}
	}
	else
	{
		while ((int)shell->ix->x != shell->input[shell->ix->y]->len)
			move_right(shell);
	}
	return (0);
}

/*
int			update_del(t_sess *sess)
{
	int		len;

	if (sess->input_ix == sess->input_text[sess->input_line]->len)
		return (0);
	remove_str(sess->input_text[sess->input_line], sess->input_ix);
	sess->input_len -= 1;
	len = ft_strlen(&sess->input_text[sess->input_line]->text[sess->input_ix]);
	write(1, &sess->input_text[sess->input_line]->text[sess->input_ix], len);
	write(1, " ", 1);
	ft_move_cursor(K_LEFT, len + 1);
	return (0);
}
*/
/*
int		update_del(t_sess *sess)
{
	int		len;

	if (sess->input_text[sess->input_ix] == '\n')
		--(sess->input_lines);
	if (sess->input_ix == (int)sess->input_len)
		return (0);
	len = ft_strlen(&sess->input_text[sess->input_ix]);
	ft_memmove(&sess->input_text[sess->input_ix], &sess->input_text[sess->input_ix + 1], len);
	sess->input_text[sess->input_len - 1] = '\0';
	--(sess->input_len);
	return (0);
}
*/
/*
int			update_arrowkey(int key, t_sess *sess)
{
	int	ret;

	ret = 0;
	if (key == KEY_LEFT && (sess->input_line > 0 || sess->input_ix > 0))
	{
		if (sess->input_ix == 0)
			sess->input_ix = sess->input_text[--(sess->input_line)]->len;
		else
			sess->input_ix -= 1;
		ret = -1;
		if (sess->cursor->x == 0)
		{
			ft_move_cursor(K_UP, 1);
			ft_move_cursor(K_RIGHT, sess->term_width - 1);
		}
		else
			ft_move_cursor(K_LEFT, 1);
		move_left(sess);
	}
	else if (key == KEY_RIGHT && (sess->input_line + 1 < sess->num_lines ||
			sess->input_ix < sess->input_text[sess->input_line]->len))
	{
		if (sess->input_ix == sess->input_text[sess->input_line]->len)
		{
			sess->input_ix = 0;
			sess->input_line -= 1;
		}
		else
			sess->input_ix += 1;
		if ((int)sess->cursor->x == sess->term_width - 1)
		{
			ft_move_cursor(K_DOWN, 1);
			write(1, "\r", 1);
		}
		else
			ft_move_cursor(K_RIGHT, 1);
		move_right(sess);
		ret = 1;
	}
	else if (key == KEY_UP)
	{
		if (sess->input_line > 0)
		{
			if (sess->input_text[--(sess->input_line)]->len < sess->input_ix)
				sess->input_ix = sess->input_text[sess->input_line]->len;
			ret = sess->term_width * -1;
		}
		else if (sess->input_ix + sess->prompt_str->len + 1 >= sess->term_width)
		{
			sess->input_ix -= sess->term_width;
			if (sess->input_ix < 0)
			{
				ret = (sess->term_width + sess->input_ix) * -1;
				sess->input_ix = 0;
			}
			else
				ret = sess->term_width * -1;
		}
	}
	else if (key == KEY_DOWN)
	{
		if (sess->input_line < sess->num_lines - 1)
		{
			if (sess->input_text[++(sess->input_line)]->len < sess->input_ix)
				sess->input_ix = sess->input_text[sess->input_line]->len;
			ret = sess->term_width;
		}
	else if (sess->input_ix + (sess->term_width - (sess->input_ix % sess->term_width)) <
			sess->input_text[sess->input_line]->len)
		{
			sess->input_ix += sess->term_width;
			if (sess->input_ix > sess->input_text[sess->input_line]->len)
			{
				ret = sess->term_width - (sess->input_ix - sess->input_text[sess->input_line]->len);
				sess->input_ix = sess->input_text[sess->input_line]->len;
			}
			else
				ret = sess->term_width;
		}
	}
	return  (ret);
}
*/
/*
int		update_arrowkey(int key, t_sess *sess)
{
	int		len;
	int		num_lines;
	int		ret;

	len = ft_strlen(sess->prompt_str) + 1 + sess->input_len;
	num_lines = len / sess->term_width;
	ret = 0;
	if (key == KEY_LEFT && ((sess->cursor->y == 0 && sess->cursor->x >
		ft_strlen(sess->prompt_str) + 1) || sess->cursor->y > 0))
		ret = -1;
	else if (key == KEY_RIGHT && ((int)sess->cursor->y != num_lines ||
			sess->cursor->x < len % sess->term_width))
		ret = 1;
	else if (key == KEY_UP && sess->cursor->y > 0)
		ret = -1 * (int)sess->term_width;
	else if (key == KEY_DOWN && (int)sess->cursor->y < num_lines)
	{
		if ((int)sess->cursor->y + 1 == num_lines && sess->cursor->x > len % sess->term_width)
		{
			sess->input_ix = sess->input_len;
			return (sess->term_width - sess->cursor->x + (len % sess->term_width));
		}
		ret = sess->term_width;
	}
	sess->input_ix += ret;
	return (ret);
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

int		update_home_end(int key, t_sess *sess)
{
	int		len;

	len = ft_strlen(sess->prompt_str) + sess->input_len + 1;
	if (key == KEY_HOME)
	{
		sess->input_ix = 0;
		render(sess, sess->term_width * sess->cursor->y * -1);
		return (sess->cursor->x * -1 + ft_strlen(sess->prompt_str) + 1);
	}
	else
	{
		sess->input_ix = sess->input_len - 1;
		render(sess, sess->term_width * ((len / sess->term_width) - sess->cursor->y));
		if (len % sess->term_width == 1)
			return (sess->cursor->x - ft_strlen(sess->prompt_str) - 1);
		return (sess->cursor->x);
	}
}
*/
