/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 16:16:53 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/28 16:25:24 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (count == 0);
}

int		valid_quotes(char *str)
{
	int		count;

	count = 0;
	while (*str != '\0')
	{
		if (*str == '"' || *str == '\'')
			++count;
		++str;
	}
	return (count == 0);
}
