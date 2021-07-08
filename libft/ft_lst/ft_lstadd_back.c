/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:51 by youness           #+#    #+#             */
/*   Updated: 2021/05/04 23:24:51 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstadd_back(t_list **tail, t_list *new)
{
	t_list *head;

	if (!new)
		return ;
	if (!*tail)
		*tail = new;
	else
	{
		head = *tail;
		while (head)
		{
			if (!head->next)
				break ;
			head = head->next;
		}
		head->next = new;
	}
}
