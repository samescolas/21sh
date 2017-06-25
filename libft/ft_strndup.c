/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 10:51:02 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/15 10:51:28 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, int n)
{
	char *new_str;

	if (!str)
		return ((void *)0);
	if ((new_str = ft_strnew(n)))
		ft_strncpy(new_str, (char *)str, n);
	return (new_str);
}
