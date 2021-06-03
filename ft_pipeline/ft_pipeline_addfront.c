/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeline_addfront.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:51:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/30 16:53:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipeline.h"

void	ft_pipeline_addfront(t_pipeline **tail, t_pipeline *node)
{
	if (node)
	{
		node->next = *tail;
		*tail = node;
	}
}
