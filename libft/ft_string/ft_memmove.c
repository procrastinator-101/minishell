/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:25:43 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 14:06:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	char	*ptr;
	int		i;

	if (!dst && !src)
		return (dst);
	str = (char *)dst;
	ptr = (char *)src;
	i = -1;
	if (src < dst)
		while (len--)
			str[len] = ptr[len];
	else
		while (++i < (int)len)
			str[i] = ptr[i];
	return (dst);
}
