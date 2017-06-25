/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keypress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 09:26:41 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/23 14:33:50 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"

static int get_esckey(void)
{
	char	ret;

	ret = '\0';
	if (read(STDIN_FILENO, &ret, 1) > 0)
	{
		if (ret == '[' && read(STDIN_FILENO, &ret, 1) > 0)
		{
			if (ret == 'A')
				return (KEY_UP);
			else if (ret == 'B')
				return (KEY_DOWN);
			else if (ret == 'C')
				return (KEY_RIGHT);
			else if (ret == 'D')
				return (KEY_LEFT);
			else if (ret == 'H')
				return (KEY_HOME);
			else if (ret == 'F')
				return (KEY_END);
			else
				return (ret);
		}
		else
			return (ret);
	}
	return (KEY_ESCAPE);
}

int			get_keypress(void)
{
	char		ret;

	if (read(STDIN_FILENO, &ret, 1) > 0)
	{
		if (ret == 27)
			return (get_esckey());
		else if (ret == 10 || ret == 13)
			return (KEY_ENTER);
		else
			return ((int)ret);
	}
	return ((int)'\0');
}
