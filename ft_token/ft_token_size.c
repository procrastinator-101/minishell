/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:59:07 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 15:00:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_token.h"

int	ft_token_size(t_token *tail)
{
	int	size;

	size = 0;
	while (tail)
	{
		size++;
		tail = tail->next;
	}
	return (size);
}
