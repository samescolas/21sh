/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:19:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 17:28:34 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sfhsh_types.h"

t_string	create_str(char *str)
{
	t_string	*ret;
	int			len;
	
	if ((ret = (t_string *)malloc(sizeof(t_string))))
	{
		len = ft_strlen(str);
		ret->text = str;
		ret->len = len;
	}
	return (ret);
}
