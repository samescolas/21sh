/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:44:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/09 13:09:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_sh	t_sh;

void	write_return(char *str);

void	wrap_left(t_sh *shell);
void	wrap_right(t_sh *shell);

void	move_left(t_sh *shell);
void	move_cursor_left(t_sh *shell);
void	move_ix_left(t_sh *shell);

void	move_right(t_sh *shell);
void	move_cursor_right(t_sh *shell);
void	move_ix_right(t_sh *shell);

void	move_up(t_sh *shell);
void	move_cursor_up(t_sh *shell);
void	move_ix_up(t_sh *shell);

void	move_down(t_sh *shell);
void	move_cursor_down(t_sh *shell);
void	move_ix_down(t_sh *shell);
