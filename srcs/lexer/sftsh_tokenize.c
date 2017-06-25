/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_tokenize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:19:21 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 09:46:29 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	print_error(char *str1, char *str2)
{
	if (str1)
		ft_putstr(str1);
	if (str2)
		ft_putstr(str2);
	return (0);
}

static int	count_tokens(char *command)
{
	int		num_tokens;
	char	*ptr;

	ptr = command;
	while (*ptr && (*ptr == ' ' || *ptr == ';'))
		++ptr;
	num_tokens = 0;
	while (*ptr)
	{
		++num_tokens;
		if ((*ptr == '"' || *ptr == '\'') && ft_strchr(ptr + 1, *ptr))
			ptr = ft_strchr(ptr + 1, *ptr) + 1;
		else if (*ptr == '"' || *ptr == '\'')
			return (print_error("sftsh: invalid quotations found\n", NULL));
		else if (*ptr == ';')
			++ptr;
		else
			while (*ptr &&\
					*ptr != ' ' && *ptr != ';' && *ptr != '"' && *ptr != '\'')
				++ptr;
		while (*ptr && *ptr == ' ')
			++ptr;
	}
	return (num_tokens);
}

static char	*add_string(char *start, char delim, char **ptr)
{
	int		i;
	char	*ret;

	i = 0;
	if (delim == '\0')
	{
		while (start[i] && start[i] != ' ' && start[i] != ';')
			++i;
		ret = ft_strsub(start, 0, i);
		*ptr = *ptr + i;
	}
	else
	{
		if (!(ret = ft_strnew(ft_strfind(start, delim))))
			return ((void *)0);
		while (start[i] && start[i] != delim)
		{
			ret[i] = start[i];
			++i;
		}
		ret[i] = '\0';
		*ptr += ft_strfind(start, delim) + 2;
	}
	return (ret);
}

char		**tokenize(char *command)
{
	char	**ret;
	char	*ptr;
	int		i;

	if (!(i = count_tokens(command)))
		return ((void *)0);
	if (!(ret = (char **)malloc((i + 1) * sizeof(char *))))
		return ((void *)0);
	ptr = command;
	while (*ptr && (*ptr == ' ' || *ptr == ';'))
		++ptr;
	i = 0;
	while (*ptr)
	{
		if (*ptr == '"' || *ptr == '\'')
			ret[i++] = add_string(ptr + 1, *ptr, &ptr);
		else if (*ptr == ';')
			ret[i++] = ft_strndup(ptr++, 1);
		else
			ret[i++] = add_string(ptr, '\0', &ptr);
		while (*ptr && *ptr == ' ')
			++ptr;
	}
	ret[i] = (void *)0;
	return (ret);
}
