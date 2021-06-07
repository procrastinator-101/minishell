/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:58:00 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:58:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cmd.h"

void	ft_cmd_clear(t_cmd **tail)
{
	t_cmd	*head;
	t_cmd	*next;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_cmd_del(head, del);
		head = next;
	}
	*tail = 0;
}
