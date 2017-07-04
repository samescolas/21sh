/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_string.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 17:19:20 by sescolas          #+#    #+#             */
/*   Updated: 2017/07/04 12:19:05 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "../../libft/libft.h"

t_string	*create_str(char *str)
{
	t_string	*ret;
	int			len;
	
	if ((ret = (t_string *)malloc(sizeof(t_string))))
	{
		len = ft_strlen(str);
		if (len % BUFF_SIZE != 0)
		{
			ret->text = ft_strnew(BUFF_SIZE * ((int)(len / BUFF_SIZE) + 1));
			ft_strcpy(ret->text, str);
			ft_strdel(&str);
		}
		else
		{
			ret->text = str;
		}
		ret->len = len;
	}
	return (ret);
}

t_string	*str_realloc(t_string *str)
{
	char	*tmp;

	tmp = ft_strnew(str->len + BUFF_SIZE);
	ft_strncpy(tmp, str->text, str->len);
	ft_strdel(&str->text);
	str->text = tmp;
	return (str);
}

t_string	*append_str(t_string *str, char c)
{
	if (str->len > 0 && (str->len + 1) % BUFF_SIZE == 0)
		str = str_realloc(str);
	str->text[str->len] = c;
	str->len += 1;
	return (str);
}

t_string	*insert_str(t_string *str, char c, int ix)
{
	if (str->len && (str->len % BUFF_SIZE == 0))
		str = str_realloc(str);
	if (ix == str->len)
		return (append_str(str, c));
	ft_memmove(&str->text[ix + 1], &str->text[ix], ft_strlen(&str->text[ix]));
	str->text[ix] = c;
	str->len += 1;
	return (str);
}

t_string	*remove_str(t_string *str, int ix)
{
	if (ix < 0 || ix >= str->len)
		return (str);
	if (ix == str->len - 1)
		str->text[ix] = '\0';
	else
	{
		ft_memmove(
				&str->text[ix],
				&str->text[ix + 1],
				ft_strlen(&str->text[ix]));
		str->text[str->len - 1] = '\0';
	}
	str->len -= 1;
	return (str);
}
