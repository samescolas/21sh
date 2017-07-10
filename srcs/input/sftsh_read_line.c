/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/10 16:17:09 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_read_line.h"
#include "sftsh_utils.h"
#include "sftsh_vars.h"
#include "sftsh_types.h"
#include "ft_keypress.h"
#include "ft_termcap.h"

void		resize_input(t_string ***input, int len)
{
	t_string	**tmp;
	int			i;

	if(!(tmp = (t_string **)malloc((len + BUFF_LINES) * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < len)
		tmp[i] = (*input)[i];
	free(*input);
	*input = tmp;
}

/*
void		resize_input(t_sh *shell)
{
	t_string	**tmp;
	int			i;

	if(!(tmp = (t_string **)malloc((shell->lines + BUFF_LINES) * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (++i < (int)shell->lines)
		tmp[i] = shell->input[i];
	tmp[i] = create_str(ft_strnew(BUFF_SIZE));
	write(1, shell->input[0]->text, shell->input[0]->len);
	free_strarr(&shell->input, shell->lines);
	&shell->input = &tmp;
	write(1, "here", 4);
	write(1, shell->input[0]->text, shell->input[0]->len);
	write(1, "z", 1);
}
*/

void	reset_shell(t_sh *shell)
{
	free_strarr(&shell->input, shell->lines);
	if (!(shell->input = (t_string **)malloc((BUFF_LINES + 1) * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	shell->input[0] = create_str(ft_strnew(BUFF_SIZE));
	delete_coord(&shell->strt);
	shell->strt = get_cursor_position();
	delete_coord(&shell->curr);
	shell->curr = create_coord(
			shell->strt->x + shell->prompt[0]->len + 1, shell->strt->y);
	shell->ix->x = 0;
	shell->ix->y = 0;
	shell->lines = 1;
}

/*
** Updates session based on pressed key.
*/
static int process_keypress(int key, t_sh *shell)
{
	if (ft_isprint(key) && key != KEY_ENTER)
		return (update_printable(key, shell));
	else if (key == KEY_BKSPC)
		return (update_bkspc(shell));
	else if (IS_ARROWKEY(key))
		return (update_arrowkey(key, shell));
	else if (key == '\n')
		return (update_newline(shell));
	else if (key == KEY_HOME || key == KEY_END)
		return (update_home_end(key, shell));
	else if (key == KEY_DEL)
		return (update_del(shell));
	return (0);
}

int		get_command_str(t_sh *shell)
{
	int		key;
	t_coord	*tmp;

	reset_shell(shell);
	ft_padstr(shell->prompt[0]->text, 1, shell->prompt[1]->text);
	while ((key = get_keypress()) != '~')
	{
		if (!key)
			continue ;
		if (key == 'P')
		{
			tmp = get_cursor_position();
			ft_putstr("\n(");
			ft_putnbr(tmp->x);
			ft_putstr(", ");
			ft_putnbr(tmp->y);
			ft_putstr(")\n");
			exit(0);
		}
		if (key == KEY_ESCAPE)
			return (1); // vim mode
		else if (key == KEY_ENTER)
		{
			if (valid_brackets(shell->input, shell->lines) == 1 && valid_quotes(shell->input, shell->lines) == 1)
				break ;
			else
			{
				if (process_keypress('\n', shell) < 0)
					return (1);
			}
		}
		else if (key != '\0')
			if (process_keypress(key, shell) == 42)
				return (1);
	}
	return (0);
}
