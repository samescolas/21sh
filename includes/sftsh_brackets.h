/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_brackets.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:27:06 by sescolas          #+#    #+#             */
/*   Updated: 2017/04/13 17:29:51 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_BRACKETS_H
# define SFTSH_BRACKETS_H

# define MAX_DEPTH 32

int		valid_brackets(char *str);
int		is_close_bracket(char c);
int		is_open_bracket(char c);
int		is_bracket(char c);

#endif
