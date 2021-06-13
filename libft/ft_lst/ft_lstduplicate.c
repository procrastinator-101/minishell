/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstduplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youness <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 23:24:52 by youness           #+#    #+#             */
/*   Updated: 2021/05/04 23:24:52 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lst.h"

t_list	*ft_lstduplicate(t_list *src, void *(*dup)(void *), void (*del)(void*))
{
	void	*content;
	t_list	*dst;
	t_list	*node;

	dst = NULL;
	while (src)
	{
		content = dup(src->content);
		node = ft_lstnew(content);
		if (!node || !content)
		{
			if (content)
				del(content);
			ft_lstclear(&dst, free);
			return (0);
		}
		node->next = 0;
		ft_lstadd_back(&dst, node);
		src = src->next;
	}
	return (dst);
}
