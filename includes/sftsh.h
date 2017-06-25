/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 09:42:03 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/01 10:14:54 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_H
# define SFTSH_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_command	t_command;
typedef struct s_term		t_term;

int		sftsh(char ***envp);
int		sftsh_exec(t_command *command);

#endif
