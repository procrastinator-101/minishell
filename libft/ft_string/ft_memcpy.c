/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:28:10 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/01 16:30:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char				*b_ptr;
	char				*b_ptr2;
	unsigned long long	*qw_ptr;
	unsigned long long	*qw_ptr2;

	qw_ptr = (unsigned long long *)dst;
	qw_ptr2 = (unsigned long long *)src;
	while (n >= sizeof(unsigned long long))
	{
		*qw_ptr = *qw_ptr2;
		qw_ptr++;
		qw_ptr2++;
		n -= sizeof(unsigned long long);
	}
	b_ptr = (char *)qw_ptr;
	b_ptr2 = (char *)qw_ptr2;
	while (n--)
	{
		*b_ptr = *b_ptr2;
		b_ptr++;
		b_ptr2++;
	}
	return (dst);
}
