/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scmd_addfront.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 14:36:07 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/27 18:25:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scmd.h"

void	ft_scmd_addfront(t_scmd **tail, t_scmd *node)
{
	if (!*tail)
	{
		*tail = node;
		return ;
	}
	(*tail)->previous = node;
	node->next = *tail;
	*tail = node;
}
