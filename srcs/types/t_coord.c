/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_coord.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 08:51:35 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/31 09:54:56 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_utils.h"

t_coord		*create_coord(size_t x, size_t y)
{
	t_coord		*ret;

	if (!(ret = (t_coord *)malloc(sizeof(t_coord))))
		ft_fatal("sftsh: err: out of memory\n");
	ret->x = x;
	ret->y = y;
	return (ret);
}
