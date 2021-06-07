/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_addfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:56:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/24 14:56:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cmd.h"

void	ft_cmd_addfront(t_cmd **tail, t_cmd *node)
{
	if (!*tail)
	{
		*tail = node;
		return ;
	}
	node->next = *tail;
	*tail = node;
}
