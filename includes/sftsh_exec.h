/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_exec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:33:36 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/15 13:06:39 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_EXEC_H
# define SFTSH_EXEC_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_command	t_command;

int		sftsh_exec(t_command *command);

#endif
