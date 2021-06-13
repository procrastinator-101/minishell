/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:00:36 by yarroubi          #+#    #+#             */
/*   Updated: 2021/03/22 19:28:15 by youness          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_bzero(void *s, size_t n)
{
	char		*b_ptr;
	long long	*qw_ptr;

	qw_ptr = s;
	while (n >= sizeof(long long))
	{
		*qw_ptr = 0;
		n -= sizeof(long long);
		qw_ptr++;
	}
	b_ptr = (char *)qw_ptr;
	while (n > 0)
	{
		*b_ptr = 0;
		b_ptr++;
		n--;
	}
}
