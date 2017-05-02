/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_brackets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:26:41 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/12 20:26:58 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_brackets.h"

int	is_close_bracket(char c)
{
	return (c == ')' || c == ']');
}

int	is_open_bracket(char c)
{
	return (c == '(' || c == '[');
}

int	is_bracket(char c)
{
	return (is_open_bracket(c) || is_close_bracket(c));
}
