/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 10:03:22 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/06 15:47:03 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TERMCAP_H
# define FT_TERMCAP_H

# include <unistd.h>
# include <termcap.h>
# include <sys/ioctl.h>

# define CL tgetstr("cl", (void *)0)
# define CM tgetstr("cm", (void *)0)
# define SO tgetstr("so", (void *)0)
# define SE tgetstr("se", (void *)0)
# define MR tgetstr("mr", (void *)0)
# define ME tgetstr("me", (void *)0)
# define MB tgetstr("mb", (void *)0)
# define MD tgetstr("md", (void *)0)
# define US tgetstr("us", (void *)0)
# define UE tgetstr("ue", (void *)0)
# define VI tgetstr("vi", (void *)0)
# define VE tgetstr("ve", (void *)0)
# define VS tgetstr("vs", (void *)0)
# define AS tgetstr("as", (void *)0)
# define AE tgetstr("ae", (void *)0)
# define BL tgetstr("bl", (void *)0)
# define VB tgetstr("vb", (void *)0)
# define K_RIGHT tgetstr("nd", (void *)0)
# define K_LEFT tgetstr("le", (void *)0)
# define K_UP tgetstr("up", (void *)0)
# define K_DOWN tgetstr("do", (void *)0)

typedef struct s_coord	t_coord;
typedef struct s_term	t_term;
typedef struct s_string	t_string;
typedef struct s_sh		t_sh;

int		ft_putc(int c);
void	ft_putstr_mode(char *str, char *mode);
void	ft_move_cursor(char *direction, int n);
void	ft_write_loc(t_string *str, t_coord pos);

#endif
