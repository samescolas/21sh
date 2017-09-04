/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:58:05 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 15:28:41 by sescolas         ###   ########.fr       */
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
	free(*arr);
	arr = (void *)0;
}
