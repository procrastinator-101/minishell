/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:40:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:03:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

t_token	*ft_token_create(char *str, t_metadata *meda, int size, int type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (0);
	node->str = ft_strndup(str, size);
	node->meda = ft_metadata_ndup(meda, size);
	node->type = type;
	node->next = 0;
	node->hasquotes = 0;
	if (!node->str || !node->meda)
		ft_token_harddel(&node);
	return (node);
}
