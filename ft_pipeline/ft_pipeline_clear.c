/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_clear.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:53:37 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 16:55:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipeline.h"

void	ft_pipeline_clear(t_pipeline **tail)
{
	t_pipeline	*next;
	t_pipeline	*head;

	head = *tail;
	while (head)
	{
		next = head->next;
		ft_pipeline_del(head);
		head = next;
	}
	*tail = 0;
}
