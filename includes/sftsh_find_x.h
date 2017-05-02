/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_find_x.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:56:08 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 17:21:21 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_FIND_X_H
# define SFTSH_FIND_X_H

# define MAX_PATHLEN 512

char	*find_path(char *command, char **envp);

#endif
