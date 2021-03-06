/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 16:44:42 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/11 10:14:40 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_sh	t_sh;

void	write_return(char *str, t_coord *start, int padding);
void	write_arr_return(t_string **arr, t_coord *start, int len);

void	clear_line(int len);

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
