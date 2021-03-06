/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keypress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/23 09:26:41 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 13:40:40 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_read_line.h"

static int	get_arrow(int key)
{
	if (key == 'A')
		return (KEY_UP);
	else if (key == 'B')
		return (KEY_DOWN);
	else if (key == 'C')
		return (KEY_RIGHT);
	else if (key == 'D')
		return (KEY_LEFT);
	return ('\0');
}

static int get_esckey(void)
{
	char	ret;

	ret = '\0';
	if (read(STDIN_FILENO, &ret, 1) > 0)
	{
		if (ret == '[' && read(STDIN_FILENO, &ret, 1) > 0)
		{
			if (ret >= 'A' && ret <= 'D')
				return (get_arrow(ret));
			else if (ret == 'H')
				return (KEY_HOME);
			else if (ret == 'F')
				return (KEY_END);
			else if (ret == '3')
			{
				if (read(STDIN_FILENO, &ret, 1) > 0 && ret == '~')
					return (KEY_DEL);
				else
					return (ret);
			}
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
		else if (ret == 13)// || ret == 13)
			return (KEY_ENTER);
		else if (ret == '^')
			write(1, "CTRL", 4);
		else if (ret > 31 && ret < 127)
			return (ret);
		else
			return ((int)ret);
	}
	else
		return (get_keypress());
	return ((int)'\0');
}
