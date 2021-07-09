/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:12:59 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 18:14:30 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

void	ft_token_addback(t_token **tail, t_token *node)
{
	t_token	*head;

	if (!node)
		return ;
	if (!*tail)
		*tail = node;
	else
	{
		head = *tail;
		while (head)
		{
			if (!head->next)
				break ;
			head = head->next;
		}
		head->next = node;
	}
}
