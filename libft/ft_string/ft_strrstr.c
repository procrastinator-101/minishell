/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:33:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/02 17:00:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
** this function looks for the last occurence of needle in the haystack
*/

char	*ft_strrstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int	needle_len;
	int	haystack_len;

	if (!haystack || !needle)
		return (0);
	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	while (haystack_len >= needle_len)
	{
		i = haystack_len - 1;
		j = needle_len - 1;
		while (j >= 0 && i >= j)
		{
			if (needle[j] != haystack[i])
				break ;
			if (j == 0)
				return ((char *)(haystack + i));
			i--;
			j--;
		}
		haystack_len--;
	}
	return (0);
}
