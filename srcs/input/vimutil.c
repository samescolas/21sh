/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vimutil.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 12:20:41 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/25 12:36:57 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"

int		is_vimarrow(int key)
{
	if (IS_ARROWKEY(key))
		return (1);
	return (key == 'h' || key == 'j' || key == 'k' || key == 'l');
}
