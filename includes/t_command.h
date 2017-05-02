/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_command.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:07:45 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/12 20:10:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_COMMAND_H
# define T_COMMAND_H

void		expand_command(t_command *command);
void		push_command(t_command **stack, t_command *command);
void		free_command(t_command *command);
void		free_commands(t_command **stack);
t_command	*pop_command(t_command **stack);
t_command	*create_command(char *command, char **env);

#endif
