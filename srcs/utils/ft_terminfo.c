/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_terminfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 15:22:48 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 15:19:43 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_termcap.h"
#include "sftsh_utils.h"
#include "sftsh_types.h"
#include "../../libft/libft.h"

static size_t	get_winsize(char dim)
{
	struct winsize	screen_size;

	if (ioctl(STDIN_FILENO, TIOCGWINSZ, &screen_size) == -1)
		ft_fatal("err: unable to determine terminal dimensions\n\r");
	if (dim == 'c' || dim == 'w')
		return ((size_t)screen_size.ws_col);
	return ((size_t)screen_size.ws_row);
}

size_t			get_term_width(void)
{
	return (get_winsize('w'));
}

size_t			get_term_height(void)
{
	return (get_winsize('h'));
}

t_coord			*get_cursor_position(void)
{
	unsigned int	i;
	char			buf[32];
	char			**tmp;
	t_coord			*ret;

	if (write(STDOUT_FILENO, "\x1b[6n", 4) != 4)
		ft_fatal("err: unable to determine cursor location\n");
	i = -1;
	while (++i < sizeof(buf) - 1)
	{
		if (read(STDOUT_FILENO, &buf[i], 1) != 1)
			break ;
		if (buf[i] == 'R')
			break ;
	}
	buf[i] = '\0';

	if (buf[0] != '\x1b' || buf[1] != '[')
		return (get_cursor_position());
	tmp = ft_strsplit(&buf[2], ';');
	ret = create_coord(ft_atoi(tmp[1]) - 1, ft_atoi(tmp[0]) - 1);
	ft_strarrdel(&tmp);
	return (ret);
}
