/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:55:29 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/05 15:40:45 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "../../libft/libft.h"

t_string	*join_strs(t_string **arr, int len,  char glue)
{
	t_string	*ret;
	int			ret_len;
	int			ix;

	ix = -1;
	ret_len = 0;
	while (++ix < len)
		ret_len += arr[ix]->len;
	ret = create_str(ft_strnew(ret_len + len - 1));
	ix = -1;
	while (++ix < len)
	{
		ft_strncat(ret->text, arr[ix]->text, arr[ix]->len);
		if (ix + 1 < len)
			ft_strncat(ret->text, &glue, 1);
	}
	return (ret);
}

void	free_str(t_string **str)
{
	if ((*str)->len && (*str)->text)
		ft_strdel(&(*str)->text);
	free(*str);
	*str = (void *)0;
}

void	free_strarr(t_string ***strs, int len)
{
	int		ix;

	ix = -1;
	while (++ix < len)
		free_str(&(*strs)[ix]);
	*strs = (void *)0;
}
