/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:52 by youness           #+#    #+#             */
/*   Updated: 2021/05/04 23:24:52 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list	*ft_lstlast(t_list *tail)
{
	while (tail)
	{
		if (!tail->next)
			return (tail);
		tail = tail->next;
	}
	return (tail);
}
