/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:19:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/18 16:32:08 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_brackets.h"
#include "sftsh_tokenize.h"

static void		print_error_message(void)
{
	write(2, "invalid brackets found\n", 23);
	exit(0);
}

static int		is_valid_command(char *command)
{
	if (ft_strcount(command, '\'') % 2 || ft_strcount(command, '"') % 2)
		return (0);
	return (1);
}

static int		count_tokens(char *command)
{ 
	int		num_tokens;
	int		i;
	int		offset;

	num_tokens = 0;
	i = 0;
	while (command[i] && command[i] == ' ')
		++i;
	while (command[i])
	{
		if (command[i] == '"' || command[i] == '\'')
			i += ft_strfind(&(command[i + 1]), command[i]) + 2;
		else
			i += ft_strfind(&(command[i]), ' ');
		if (command[i - 2] && command[i - 1] == ';' && command[i - 2] != ' ')
			++num_tokens;
		while (command[i] && command[i] == ' ')
			++i;
		++num_tokens;
	}
	return (num_tokens);
}

static void		add_string(char **list, char *str, size_t size, int *ix)
{
	int		semicolon;
	char	*ret;

	ret = (void *)0;
	semicolon = (str[size - 1] == ';' && size > 1);
	if ((ret = ft_strnew(size)))
		ft_strncpy(ret, str, size);
	list[(*ix)++] = ret;
	if (semicolon)
	{
		ret[size - 1] = '\0';
		list[(*ix)++] = ft_strdup(";");
	}
}
/*
static char		*create_string(char *str, size_t size)
{
	char	*ret;

	ret = (void *)0;
	if (!(ret = ft_strnew(size)))
		return (ret);
	ft_strncpy(ret, str, size);
	return (ret);
}
*/

char		**tokenize(char *command)
{ 
	char	**ret;
	int		i;
	int		j;

	if (!(ret = (char **)malloc((count_tokens(command) + 1) * sizeof(char *))))
		return (ret);
	i = 0;
	j = 0;
	while (command[i] && command[i] == ' ')
		++i;
	while (command[i])
	{
		if (command[i] == '"' || command[i] == '\'')
		{
			add_string(ret, &(command[i + 1]), ft_strfind(&(command[i + 1]), command[i]), &j);
			i += ft_strfind(&(command[i + 1]), command[i]) + 2;
		}
		else
		{
			add_string(ret, &command[i], ft_strfind(&command[i], ' '), &j);
			i += ft_strfind(&(command[i]), ' ');
		}
		while (command[i] && command[i] == ' ')
			++i;
	}
	ret[j] = (void *)0;
	return (ret);
}
