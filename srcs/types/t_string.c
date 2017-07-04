/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:19:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 18:32:11 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "../../libft/libft.h"

t_string	*create_str(char *str)
{
	t_string	*ret;
	
	if ((ret = (t_string *)malloc(sizeof(t_string))))
	{
		ret->text = str;
		ret->len = ft_strlen(str);
	}
	return (ret);
}
