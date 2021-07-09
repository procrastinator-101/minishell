/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:30:19 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 13:06:21 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

char	*ft_itoa(int n)
{
	char	*ptr;
	int		i;
	int		len;
	int		k;

	i = 1;
	k = n;
	while (k / 10 && ++i)
		k /= 10;
	i = (n < 0 ? i + 2 : i + 1);
	ptr = (char *)malloc(i * sizeof(char));
	if (ptr == 0)
		return (0);
	if (n < 0)
		ptr[0] = 45;
	len = i;
	ptr[len - 1] = 0;
	n == 0 ? ptr[0] = '0' : k--;
	i = 0;
	while ((n / 10 || n % 10) && ++i)
	{
		ptr[len - i - 1] = 48 + (n < 0 ? -1 : 1) * (n % 10);
		n /= 10;
	}
	return (ptr);
}
