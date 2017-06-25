/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/06 10:24:58 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/23 14:40:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh.h"
#include "sftsh_env.h"
#include "sftsh_utils.h"
#include "sftsh_atexit.h"

int		main(int argc, char **argv, char **envp)
{
	char			**envp_cpy;

	if (argc > 2 || argv[1])
	{
		/*
		** read from file if one exists?
		*/
		write(2, "sftsh: please start shell and type stuff like a human\n", 51);
		return (0);
	}
	load_terminal();
	envp_cpy = copy_env(envp);
	if (sftsh(&envp_cpy) != 0)
		write(2, "unable to read from environment\n", 32);
	ft_atexit();
	return (0);
}
