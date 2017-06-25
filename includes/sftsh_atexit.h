/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_atexit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:06:00 by sescolas          #+#    #+#             */
/*   Updated: 2017/05/30 09:26:49 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_ATEXIT_H
# define SFTSH_ATEXIT_H

# define STRING_BUFFER 5
# define FUNCTION_BUFFER 5

typedef void	(*t_void_func_ptr)(void);

void	ft_str_atexit(int loading, char *str_to_free);
void	ft_func_atexit(int loading, void (*func_to_load)(void));
void	ft_atexit(void);

#endif
