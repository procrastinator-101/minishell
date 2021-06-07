/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:40:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 18:12:50 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

t_token	*ft_token_create(char *line, char *quotes, int size, int type)
{
	t_token	*node;

	node = malloc(sizeof(t_token));
	if (!node)
		return (0);
	node->str = ft_strndup(line, size);
	node->quotes = ft_strndup(quotes, size);
	node->type = type;
	node->next = 0;
	if (!node->str || !node->quotes)
		ft_token_harddel(&node);
	return (node);
}
