/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:01:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 18:03:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

void	ft_token_clear(t_token **tail)
{
	t_token	*next;
	t_token	*head;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_token_del(head);
		head = next;
	}
	*tail = 0;
}
