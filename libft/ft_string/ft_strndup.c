/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 14:47:53 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 15:24:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	i;
	char	*ptr;

	i = 0;
	while (i < n && str[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (0);
	ptr[i] = 0;
	while (i--)
		ptr[i] = str[i];
	return (ptr);
}
