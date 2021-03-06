/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:39:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/05 19:21:35 by sescolas         ###   ########.fr       */
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

void	reset_shell(t_sh *shell)
{
	char	*tmp;

	ft_putendl("inside reset_shell");
	tmp = ft_strnew(BUFF_SIZE);
	ft_putendl("created new string...");
	free_strarr(&shell->input, shell->lines);
	ft_putendl("freed array");
	if (!(shell->input = (t_string **)malloc((BUFF_LINES + 1) * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	ft_putendl("allocated space for input");
	shell->input[0] = create_str(tmp);
	ft_putendl("deleting old start coordinate");
	delete_coord(&shell->strt);
	ft_putendl("deleted old start coordinate");
	shell->strt = get_cursor_position();
	ft_putendl("deleting old curr coordinate");
	delete_coord(&shell->curr);
	ft_putendl("deleted old curr coordinate");
	shell->curr = create_coord(
			shell->strt->x + shell->prompt[0]->len + 1, shell->strt->y);
	shell->ix->x = 0;
	shell->ix->y = 0;
	shell->lines = 1;
	shell->history->cursor = (void *)0;
	ft_putendl("leaving reset_shell");
}

/*
** Updates session based on pressed key.
*/
int 	process_keypress(int key, t_sh *shell)
{
	if (ft_isprint(key) && key != KEY_ENTER)
		return (update_printable(key, shell));
	else if (key == KEY_BKSPC)
		return (update_bkspc(shell));
	else if (IS_ARROWKEY(key))
		return (update_arrowkey(key, shell));
	else if (key == '\n')
		return (update_newline(shell));
	else if (key == KEY_HOME)
		return (update_home(shell));
	else if (key == KEY_END)
		return (update_end(shell));
	else if (key == KEY_DEL)
		return (update_del(shell));
	return (0);
}

int		get_command_str(t_sh *shell)
{
	int		key;

	ft_putendl("inside get_command_str");
	reset_shell(shell);
	ft_padstr(shell->prompt[0]->text, 1, shell->prompt[1]->text);
	while ((key = get_keypress()) != '\0')
	{
		if (key == KEY_ESCAPE && enter_vim_mode(shell) == 1)
			return (1);
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
		else if (key != '\0' && process_keypress(key, shell) == 42)
			return (1);
	}
	if (shell->ix->y > 0 || shell->input[0]->len > 0)
		return (update_shell_history(shell));
	return (0);
}
