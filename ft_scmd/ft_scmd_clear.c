/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:41:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 15:01:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scmd.h"

void	ft_scmd_clear(t_scmd **tail)
{
	t_scmd	*head;
	t_scmd	*next;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_scmd_del(head);
		head = next;
	}
	*tail = 0;
}
