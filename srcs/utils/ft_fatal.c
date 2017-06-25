/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fatal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:20:12 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 10:11:04 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "sftsh_atexit.h"

void	ft_fatal(char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n\r", 1);
	ft_atexit();
}
