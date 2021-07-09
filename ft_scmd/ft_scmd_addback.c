/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:34:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/27 18:24:37 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scmd.h"

void	ft_scmd_addback(t_scmd **tail, t_scmd *node)
{
	t_scmd	*head;

	if (!*tail)
	{
		*tail = node;
		return ;
	}
	head = *tail;
	while (head->next)
		head = head->next;
	head->next = node;
	node->previous = head;
}
