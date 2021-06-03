/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:51 by youness           #+#    #+#             */
/*   Updated: 2021/05/05 14:07:30 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstclear(t_list **tail, void (*del)(void*))
{
	t_list	*next;
	t_list	*head;

	head = *tail;
	while (head)
	{
		next = head->next;
		del(head->content);
		free(head);
		head = next;
	}
	*tail = 0;
}
