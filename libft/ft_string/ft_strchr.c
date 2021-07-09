/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:43:19 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 13:11:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	int		len;
	char	a;

	a = c;
	len = 0;
	while (s[len])
		len++;
	i = -1;
	while (++i < len + 1)
		if (s[i] == a)
			return ((char *)(s + i));
	return (0);
}
