/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:28:10 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 14:07:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;
	char			*str;
	char			*ptr;

	if (!dst && !src)
		return (dst);
	str = (char *)dst;
	ptr = (char *)src;
	i = -1;
	while (++i < n)
		str[i] = ptr[i];
	return (dst);
}
