/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 16:42:33 by sescolas          #+#    #+#             */
/*   Updated: 2017/06/24 14:56:00 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_KEYPRESS_H
# define FT_KEYPRESS_H

typedef struct s_sess	t_sess;

int		ft_backspace(t_sess *sess);
int		ft_arrowkeys(int c, t_sess *sess);
//int		ft_delete(char **line, t_term *term);
int		ft_printable(char c, t_sess *sess);
//int		ft_escape(char **line, t_term *term);

#endif
