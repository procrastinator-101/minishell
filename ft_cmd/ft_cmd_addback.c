/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:54:54 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:55:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cmd.h"

void	ft_cmd_addback(t_cmd **tail, t_cmd *node)
{
	t_cmd	*head;

	if (!*tail)
	{
		*tail = node;
		return ;
	}
	head = *tail;
	while (head->next)
		head = head->next;
	head->next = node;
}
