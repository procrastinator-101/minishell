/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:38:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/01 16:33:36 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	src_len = 0;
	dst_len = 0;
	i = -1;
	while (*(src + src_len))
		src_len++;
	while (dst_len < size && *(dst + dst_len))
		dst_len++;
	while (++i + 1 < size - dst_len && i < src_len)
		dst[dst_len + i] = src[i];
	if (size != dst_len && size > 0)
		dst[dst_len + i] = 0;
	return (dst_len + src_len);
}
