/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sftsh_read_line.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:32:51 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/06 16:02:33 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SFTSH_READ_LINE_H
# define SFTSH_READ_LINE_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_sh	t_sh;
typedef struct s_coord	t_coord;
typedef struct s_string	t_string;

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

# define BUFF_SIZE 64
# define BUFF_LINES 16
# define DEFAULT_PROMPT "sftsh $"
# define DEFAULT_COLOR "\x1B[94m"

# define IS_ARROWKEY(key) (key >= KEY_UP && key <= KEY_RIGHT)

/*
typedef struct 	s_sh
{
	t_string	**input;
	t_string	prompt[2];
	t_string	*cb;
	t_coord		*loc;
	t_coord		*ix;
	t_coord		*term;
	size_t		lines;
}				t_sh;

typedef struct	s_sess
{
	t_string	**input_text;
	int			input_ix;
	int			input_line;
	int			num_lines;
	int			input_len;
	int			term_width;
	int			term_height;
	t_string	*clipboard;
	t_string	*prompt_str;
	t_string	*prompt_color;
	t_coord		*cursor;
}				t_sess;
*/

int				get_keypress(void);
int				get_command_str(t_sh *shell);
t_sh			*create_shell(void);

int				valid_quotes(t_string **str, int lines);
int				valid_brackets(t_string **str, int lines);

size_t			get_term_width(void);
size_t			get_term_height(void);

int				update_printable(int key, t_sh *shell);

#endif
