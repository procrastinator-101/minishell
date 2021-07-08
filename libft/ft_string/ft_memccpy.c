/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:45:20 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 16:07:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;
	unsigned char	*ptr;

	if (!n)
		return (0);
	str = (unsigned char *)dst;
	ptr = (unsigned char *)src;
	a = c;
	i = -1;
	while (++i < n && ptr[i] != a)
		str[i] = ptr[i];
	if (ptr[i] == a)
		str[i] = a;
	return (ptr[i] == a ? (void *)(str + i + 1) : NULL);
}
