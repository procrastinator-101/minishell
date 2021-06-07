/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:52 by youness           #+#    #+#             */
/*   Updated: 2021/05/04 23:24:52 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstdel_back(t_list **tail, void (*del)(void*))
{
	t_list	*head;

	if (!*tail)
		return ;
	head = *tail;
	if (!head->next)
	{
		del(head->content);
		free(head);
		*tail = 0;
		return ;
	}
	while (head->next)
	{
		if (!head->next->next)
			break ;
		head = head->next;
	}
	del(head->next->content);
	free(head->next);
	head->next = 0;
}
