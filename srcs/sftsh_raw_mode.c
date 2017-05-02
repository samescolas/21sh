/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_raw_mode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:53:15 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/12 19:53:18 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_raw_mode.h"

struct termios	default_settings;

static void	turn_off_keyboard_echo(struct termios *settings)
{
	settings->c_lflag &= ~(ECHO);
}

static void	turn_off_canonical_mode(struct termios *settings)
{
	settings->c_lflag &= ~(ICANON);
}

static void	turn_off_ctrl_c(struct termios *settings)
{
	settings->c_lflag &= ~(ISIG);
}

static void	reset_settings(void)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &default_settings);
}

void		raw_mode(void)
{
	struct termios	updated_settings;

	tcgetattr(STDIN_FILENO, &default_settings);
	atexit(reset_settings); /* should I call reset_settings() prior to exit instead? */
	tcgetattr(STDIN_FILENO, &updated_settings);
	updated_settings.c_iflag &= ~(IXON);
	turn_off_canonical_mode(&updated_settings);
	turn_off_keyboard_echo(&updated_settings);
	turn_off_ctrl_c(&updated_settings);
	//updated_settings.c_lflag &= ~(ISIG | ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &updated_settings);
}
