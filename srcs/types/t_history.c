/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_history.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 10:31:04 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/04 11:23:33 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_vars.h"
#include "sftsh_utils.h"

#include "../../libft/libft.h"

t_history	*init_history(void)
{
	t_history	*ret;

	if (!(ret = (t_history *)malloc(sizeof(t_history))))
		ft_fatal("err: out of memory\n");
	list_add(&ret->list, create_list_item(ft_strdup("beginning of history")));
	ret->cursor = (void *)0;
	ret->len = 1;
	return (ret);
}

void		add_history(t_history *hist, char *item)
{
	t_list	*tmp;

	if ((hist->len + 1) > MAX_HISTORY)
	{
		tmp = hist->list;
		hist->list = hist->list->next;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
		free_list_item(tmp);
	}
	else
		hist->len += 1;
	list_add(&hist->list, create_list_item(item));
}
