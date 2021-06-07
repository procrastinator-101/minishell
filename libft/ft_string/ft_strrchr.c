/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:06:17 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 14:23:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	a;

	a = c;
	len = 0;
	while (s[len])
		len++;
	i = len + 1;
	while (i--)
		if (s[i] == a)
			return ((char *)(s + i));
	return (0);
}
