/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:16:53 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/28 17:21:01 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

int		valid_brackets(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '(' || *str == '[' || *str == '{')
			++count;
		else if (*str == ')' || *str == ']' || *str == '}')
			--count;
		++str;
	}
	if (count == 0)
		return (1);
	return (0);
}

int		valid_quotes(char *str)
{
	int		count[2];

	count[0] = 0;
	count[1] = 0;
	while (*str != '\0')
	{
		if (*str == '"')
			++count[0];
		else if (*str == '\'')
			++count[1];
		++str;
	}
	if (count[0] % 2 == 0 && count[1] % 2 == 0)
		return (1);
	return (0);
}
