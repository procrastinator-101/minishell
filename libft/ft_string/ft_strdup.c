/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:54:22 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/20 13:11:16 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr == 0)
		return (0);
	ptr[i] = 0;
	while (--i >= 0)
		ptr[i] = s1[i];
	return (ptr);
}
