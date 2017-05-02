/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:24:58 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 13:11:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_raw_mode.h"
#include "sftsh_env.h"
#include "sftsh.h"
#include "minishell.h"

int		main(int argc, char **argv, char **envp)
{
	char	**env_cpy;
	char	**tokens;
	int		i;

	raw_mode();
	env_cpy = copy_env(envp);
	if (sftsh(envp) != 0)
		write(2, "something went wrong!\n", 22);
	restore_env(envp, env_cpy); /* I'm not sure this is actually even necessary. */
	return (0);
}
