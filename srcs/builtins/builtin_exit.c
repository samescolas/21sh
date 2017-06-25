/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:30:15 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 09:19:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_atexit.h"

int		sftsh_exit(t_command *command)
{
	free_command(command);
	ft_atexit();
	return (0);
}
