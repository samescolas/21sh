/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:53:15 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/28 15:51:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_atexit.h"
#include "sftsh_utils.h"
#include "../../libft/libft.h"

static void	reset_terminal_settings(struct termios *orig_settings)
{
	static struct termios	saved_settings;

	if (orig_settings)
		ft_memcpy(&saved_settings, orig_settings, sizeof(*orig_settings));
	else
		tcsetattr(STDIN_FILENO, 0, &saved_settings);
}

void		ft_makeraw(void)
{
	struct termios	settings;

	if (!isatty(STDIN_FILENO))
		ft_fatal("sftsh: err: this seems to be something other than a terminal...\n");
	tcgetattr(STDIN_FILENO, &settings);
	reset_terminal_settings(&settings);
	settings.c_iflag &= ~(ICRNL | IXON);
	//settings.c_oflag &= ~(OPOST); /* This is the carriage return flag. */
	settings.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	settings.c_cc[VMIN] = 0;
	settings.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &settings) == -1)
		ft_fatal("sftsh: err: unable to enter raw mode\n");
}

void		reset_terminal(void)
{
	reset_terminal_settings((void *)0);
}

void		load_terminal(void)
{
	char	*termtype;
	char	*buff;
	int		status;

	termtype = (void *)0;
	if (!(buff = (char *)malloc(2048 * sizeof(char))))
		ft_fatal("sftsh: err: out of memory\n");
	ft_str_atexit(1, buff);
	termtype = getenv("TERM");
	/* We should probably set some global or indicator that we can't
	 * use termcaps. (That is the case, right..?) */
	if (!termtype || (status = tgetent(buff, termtype)) <= 0)
		return ;
	ft_makeraw();
	ft_func_atexit(1, &reset_terminal);
}
