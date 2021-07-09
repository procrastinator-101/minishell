/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_clear.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:21:56 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 15:22:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_redirection.h"

void	ft_redirection_clear(t_redirection **tail)
{
	t_redirection	*next;
	t_redirection	*head;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_redirection_del(head);
		head = next;
	}
	*tail = 0;
}
