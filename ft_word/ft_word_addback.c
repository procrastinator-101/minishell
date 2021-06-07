/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_addback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:06:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:17:09 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_word.h"

void	ft_word_addback(t_word **tail, t_word *node)
{
	t_word	*head;

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
