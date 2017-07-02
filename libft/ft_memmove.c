/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:05:02 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/02 13:16:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If shifting left copy from left to right. otherwise copy right to left.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;

	if (dst < src)
	{
		i = -1;
		while (++i < (int)len)
			ft_memset((unsigned char *)(dst + i), (unsigned char)*((unsigned char *)src + i), 1);
	}
	else if (dst > src)
	{
		i = (int)len;
		while (i--)
			ft_memset(
				(unsigned char *)((unsigned char *)dst + i),
				(unsigned char)*((unsigned char *)src + i), 1);
	}
	return (dst);
}
