/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:14:15 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:43:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_word.h"

void	ft_word_clear(t_word **tail)
{
	t_word	*head;
	t_word	*next;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_word_del(head);
		head = next;
	}
	*tail = 0;
}
