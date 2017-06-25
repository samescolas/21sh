/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_vars.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 12:18:29 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/15 13:08:54 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_VARS_H
# define SFTSH_VARS_H

# include <signal.h>

# define MAX_PATHLEN 512
# define BUFF_SIZE 32

# define DEFAULT_PROMPT "sftsh $"
# define DEFAULT_COLOR "\x1B[94m"
# define DEFAULT_TERM "xterm-256color"
# define DEFAULT_PATH "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"

# define DEF "\x1B[0m"
# define RED "\x1B[31m"
# define BLU "\x1B[34m"
# define MAG "\x1B[35m"
# define CY1 "\x1B[36m"
# define CY2 "\x1B[37m"
# define CY3 "\x1B[96m"
# define BK2 "\x1B[90m"
# define BL2 "\x1B[94m"
# define MG2 "\x1B[95m"

volatile sig_atomic_t	g_ctrl_c_pressed;

#endif
