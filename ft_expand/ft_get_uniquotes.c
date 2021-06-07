/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_uniquotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:39:43 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 15:47:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_get_uniquotes(int size, char type)
{
	char	*quotes;

	quotes = malloc(size * sizeof(char));
	if (!quotes)
		return (0);
	quotes[--size] = 0;
	while (--size >= 0)
		quotes[size] = type;
	return (quotes);
}
