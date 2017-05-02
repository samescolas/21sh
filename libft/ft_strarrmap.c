/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 12:01:15 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 12:10:30 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strarrmap(char **arr, char *(*f)(char *))
{
	int		i;
	char	*tmp;

	i = -1;
	while (arr[++i])
	{
		tmp = arr[i];
		arr[i] = f(arr[i]);
		ft_strdel(&tmp); /* will this cause seg faults if argv? */
	}
}
