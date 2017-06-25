/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_parse.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 13:22:57 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/15 13:07:04 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_PARSE_H
# define SFTSH_PARSE_H

# include <unistd.h>

typedef struct s_command	t_command;

t_command	*parse(char *tokens, char ***envp);

#endif
