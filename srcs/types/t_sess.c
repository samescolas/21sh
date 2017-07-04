/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sess.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <sescolas@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 09:45:31 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 18:30:28 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_vars.h"
#include "sftsh_types.h"
#include "sftsh_utils.h"
#include "../../libft/libft.h"

t_sess	*create_sess()
{
	t_sess	*ret;

	if ((ret = (t_sess *)malloc(sizeof(t_sess))))
	{
		if (!(ret->input_text = (t_string **)malloc((BUFF_LINES + 1) * sizeof(t_string *))))
			ft_fatal("err: out of memory\n");
		ret->input_text[0] = create_str(ft_strnew(0));
		ret->input_ix = 0;
		ret->input_line = 0;
		ret->num_lines = 1;
		ret->input_len = 0;
		ret->clipboard = (void *)0;
		ret->prompt_str = create_str(ft_strdup(DEFAULT_PROMPT));
		ret->prompt_color = create_str(ft_strdup(DEFAULT_COLOR));
		ret->cursor = create_coord(0, 0);
		ret->term_height = get_term_height();
		ret->term_width = get_term_width();
	}
	return (ret);
}
