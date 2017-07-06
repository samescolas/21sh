/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 14:33:09 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/06 16:50:59 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_utils.h"
#include "sftsh_types.h"
#include "sftsh_read_line.h"
#include "../../libft/libft.h"

t_sh	*create_sh()
{
	t_sh	*shell;

	if ((shell = (t_sh *)malloc(sizeof(t_sh))))
	{
		if (!(shell->input = (t_string **)malloc((BUFF_LINES + 1) * sizeof(t_string *))))
			ft_fatal("err: out of memory\n");
		shell->input[0] = create_str(ft_strnew(0));
		shell->prompt[0] = create_str(ft_strdup(DEFAULT_PROMPT));
		shell->prompt[1] = create_str(ft_strdup(DEFAULT_COLOR));
		shell->cb = (void *)0;
		shell->strt = get_cursor_position();
		shell->curr = create_coord(
				shell->strt->x + shell->prompt[0]->len, shell->strt->y);
		shell->ix = create_coord(0, 0);
		shell->term = create_coord(get_term_width(), get_term_height());
		shell->lines = 1;
	}
	return (shell);
}
