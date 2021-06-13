/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:10:21 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 13:41:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)malloc(count * size);
	if (ptr == 0)
		return (0);
	i = -1;
	while (++i < count * size)
		ptr[i] = 0;
	return ((void *)ptr);
}
