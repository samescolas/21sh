/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 10:55:29 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 11:47:04 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_utils.h"
#include "../../libft/libft.h"

t_string	**split_strs(t_string *str, char glue)
{
	t_string	**ret;
	char		**tmp;
	int			i;

	tmp = ft_strsplit(str->text, glue);
	i = 0;
	while (tmp[i] != (void *)0)
		i += 1;
	if (!(ret = (t_string **)malloc(i * sizeof(t_string *))))
		ft_fatal("err: out of memory\n");
	i = -1;
	while (tmp[++i])
		ret[i] = create_str(tmp[i]);
	//ft_strarrdel(&tmp);
	return (ret);
}
