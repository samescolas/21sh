/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:58:05 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/11 18:03:39 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrdel(char ***arr)
{
	int		i;
	char	**tmp;

	tmp = *arr;
	i = -1;
	while ((*arr)[++i])
		ft_strdel(&(*arr)[i]);
	*tmp = (void *)0;
}