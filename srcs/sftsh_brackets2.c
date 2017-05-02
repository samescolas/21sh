/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_brackets2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:26:31 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 17:30:09 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "sftsh_brackets.h"

static int	matching_brackets(char b1, char b2)
{
	if (is_open_bracket(b1) && is_close_bracket(b2))
		return ((b1 == '(' && b2 == ')') || (b1 == '[' && b2 == ']'));
	else
		return ((b1 == ')' && b2 == '(') || (b1 == ']' && b2 == '['));
}

static char	brack_pop(char stack[MAX_DEPTH], int *ix)
{
	char	ret;

	ret = stack[*ix];
	stack[*ix] = '\0';
	*ix = *ix + 1;
	return (ret);
}

static void	brack_push(char stack[MAX_DEPTH], int *ix, char bracket)
{
	if (ix == 0)
		return ;
	stack[*ix - 1] = bracket;
	*ix = *ix - 1;
}

int	valid_bracket(char *str)
{
	char	brack_stack[128];
	int		stack_ix;
	int		i;

	i = 0;
	stack_ix = 128 / 2;
	ft_bzero(brack_stack, 128 * sizeof(char));
	while (str[i])
	{
		if (is_bracket(str[i]))
		{
			if (is_open_bracket(str[i]))
				brack_push(brack_stack, &stack_ix, str[i]);
			else
			{
				if (matching_brackets(str[i], brack_stack[stack_ix]))
					brack_pop(brack_stack, &stack_ix);
				else
					return (0);
			}
		}
		++i;
	}
	return (brack_stack[stack_ix] == '\0');
}
