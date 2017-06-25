/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_sess.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <sescolas@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 09:45:31 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/23 14:48:29 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"
#include "sftsh_vars.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"

t_sess	*create_sess()
{
	t_sess	*ret;

	if ((ret = (t_sess *)malloc(sizeof(t_sess))))
	{
		ret->input_text = ft_strnew(0);
		ret->input_lines = 0;
		ret->clipboard = (void *)0;
		ret->prompt_str = ft_strdup(DEFAULT_PROMPT);
		ret->prompt_color = ft_strdup(DEFAULT_COLOR);
		ret->cursor = create_coord(0, 0);
	}
	return (ret);
}
