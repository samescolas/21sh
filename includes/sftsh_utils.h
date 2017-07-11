/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:33:33 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/11 10:18:53 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_UTILS_H
# define SFTSH_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <termcap.h>
# include <termios.h>

typedef struct s_coord	t_coord;

void	load_terminal(void);
void	ft_fatal(char *err_message);
char	*find_exe_path(char *cmd_str, char **envp);
t_coord	*get_cursor_position(void);
size_t			get_term_width(void);
size_t			get_term_height(void);

# endif
