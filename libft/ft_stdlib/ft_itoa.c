/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:30:19 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 10:51:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	ft_getlen(int n)
{
	int	ret;

	ret = 1;
	while (n / 10)
	{
		ret++;
		n /= 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;

	len = ft_getlen(n) + (n < 0);
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (ptr);
	ptr[len] = 0;
	if (!n)
		ptr[0] = '0';
	else if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		len--;
		if (n < 0)
			ptr[len] = -(n % 10) + '0';
		else
			ptr[len] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}
