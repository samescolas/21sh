/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:32:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/03 17:29:17 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_READ_LINE_H
# define SFTSH_READ_LINE_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_coord	t_coord;

static const int KEY_BKSPC = 127;
static const int KEY_ENTER = 1717;
static const int KEY_UP = 1718;
static const int KEY_DOWN = 1719;
static const int KEY_LEFT = 1720;
static const int KEY_RIGHT = 1721;
static const int KEY_ESCAPE = 1722;
static const int KEY_HOME = 1723;
static const int KEY_END = 1724;
static const int KEY_DEL = 1725;

#define IS_ARROWKEY(key) (key >= KEY_UP && key <= KEY_RIGHT)

typedef struct	s_sess
{
	t_string	**input_text;
	int			input_ix;
	int			input_line;
	int			num_lines;
	int			input_len;
	int			term_width;
	t_string	*clipboard;
	t_string	*prompt_str;
	t_string	*prompt_color;
	t_coord		*cursor;
}				t_sess;

int				get_keypress(void);
int				get_command_str(t_sess *sess);
int				enter_vim_mode(t_sess *sess);
t_sess			*create_sess(void);

int				valid_quotes(char *str);
int				valid_brackets(char *str);

size_t			get_term_width(void);
size_t			get_term_height(void);

int				update_arrowkey(int key, t_sess *sess);
int				update_printable(int key, t_sess *sess);
int				update_home_end(int key, t_sess *sess);
int				update_bkspc(t_sess *sess);
int				update_del(t_sess *sess);

int				is_vimarrow(int key);
int				update_vimarrow(int key, t_sess *sess);
int				update_vimword(int key, t_sess *sess);
int				render_vimarrow(int key);
int				render_vimword(t_sess *sess);

int				render_arrowkey(int key);
int				render(t_sess *sess, int cm);
int				render_home_end(int key, t_sess *sess);
int				render_bkspc(void);
int				render_del(t_sess *sess);


//int				read_line(t_term *term);
//void			resize_buffer(char **line, t_term *term);
//t_term			*create_term(void);

#endif
