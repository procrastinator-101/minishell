/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:03:05 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 20:56:45 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	if (start >= i)
		len = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	i = -1;
	while (++i < len && s[start + i])
		ptr[i] = s[start + i];
	ptr[i] = 0;
	return (ptr);
}
