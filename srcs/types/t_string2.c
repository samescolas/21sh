/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:55:29 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 16:05:47 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "../../libft/libft.h"

t_string	*join_strs(t_string **arr, int len,  char glue)
{
	t_string	*ret;
	int			ret_len;
	int			ix;
	char		*tmp;

	ix = -1;
	ret_len = 0;
	while (++ix < len)
		ret_len += arr[ix]->len;
	tmp = ft_strnew(ret_len - 1);
	ret = create_str(tmp);
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
	//*strs = (void *)0;
}

t_string	**insert_strarr(t_string ***strs, t_string *str, int ix, int len)
{
	while (len > ix)
	{
		(*strs)[len] = (*strs)[len - 1];
		--len;
	}
	(*strs)[ix - 1] = str;
	return (*strs);
}

void	remove_strarr(t_string ***strs, int ix, int len)
{
	int		to_shift;
		ft_putnbr(ix);

	to_shift = len - ix + 1;
	free_str(&(*strs)[ix]);
	while (--to_shift)
		(*strs)[len - to_shift] = (*strs)[len - to_shift + 1];
	(*strs)[len] = (void *)0;
}
