/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_addback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:47:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 16:51:20 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipeline.h"

void	ft_pipeline_addback(t_pipeline **tail, t_pipeline *node)
{
	t_pipeline	*head;

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
