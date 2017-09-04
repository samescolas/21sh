/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sescolas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 18:35:10 by sescolas          #+#    #+#             */
/*   Updated: 2017/09/03 19:07:05 by sescolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sftsh_types.h"
#include "sftsh_utils.h"
#include "../../libft/libft.h"

t_list	*create_list_item(char *str)
{
	t_list	*ret;

	if (!(ret = (t_list *)malloc(sizeof(t_list))))
		ft_fatal("err: out of memory\n");
	if (str)
		ret->str = create_str(str);
	ret->next = NULL;
	ret->prev = NULL;
	return (ret);
}

void		list_add(t_list **list, t_list *new_node)
{
	if (!list || !*list)
	{
		*list = new_node;
		(*list)->next = *list;
		(*list)->prev = *list;
	}
	else
	{
		new_node->prev = (*list)->prev;
		new_node->next = (*list);
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
	}
}

void		free_list_item(t_list *list)
{
	(list)->next = (void *)0;
	(list)->prev = (void *)0;
	free_str(&list->str);
	free(list);
	list = (void *)0;
}

void		remove_list(t_list **list)
{
	t_list	*tmp;

	if (*list == (*list)->next)
	{
		free_list_item(*list);
		return ;
	}
	tmp = *list;
	(*list)->next->prev = (*list)->prev;
	(*list)->prev->next = (*list)->next;
	*list = (*list)->next;
	free_list_item(tmp);
}
