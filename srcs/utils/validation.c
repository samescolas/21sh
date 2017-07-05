/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:16:53 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/04 18:20:07 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "sftsh_types.h"

int		valid_brackets(t_string **str, int lines)
{
	int		count[3];
	int		ix;
	char	*tmp;

	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	ix = -1;
	while (++ix < lines)
	{
		tmp = str[ix]->text;
		while (*tmp)
		{
			if (*tmp == '(' || *tmp == ')')
				count[0] += (*tmp == '(' ? -1 : 1);
			else if (*tmp == '{' || *tmp == '}')
				count[1] += (*tmp == '{' ? -1 : 1);
			else if (*tmp == '[' || *tmp == ']')
				count[2] += (*tmp == '[' ? -1 : 1);
			tmp += 1;
		}
	}
	if (count[0] == count[1] && count[1] == count[2] && count[2] == 0)
		return (1);
	return (0);
}

int		valid_quotes(t_string **str, int lines)
{
	int		count[2];
	int		ix;
	char	*tmp;

	count[0] = 0;
	count[1] = 0;
	ix = -1;
	while (++ix < lines)
	{
		tmp = str[ix]->text;
		while (*tmp)
		{
			if (*tmp == '"')
				++count[0];
			else if (*tmp == '\'')
				++count[1];
			++tmp;
		}
	}
	if (count[0] % 2 == count[1] % 2 && count[1] % 2 == 0)
		return (1);
	return (0);
}
