/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:52 by youness           #+#    #+#             */
/*   Updated: 2021/05/04 23:24:52 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

void	ft_lstdel_front(t_list **tail, void (*del)(void*))
{
	t_list	*new_tail;

	if (!*tail)
		return ;
	new_tail = (*tail)->next;
	del((*tail)->content);
	free(*tail);
	*tail = new_tail;
}
