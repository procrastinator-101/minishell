/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 11:29:55 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 14:26:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	st_en(char const *s1, char const *set, int p, int start)
{
	int set_len;
	int bound;
	int i;
	int k;

	bound = (int)ft_strlen(s1);
	set_len = (int)ft_strlen(set);
	i = (p == 1 ? 0 : bound - 1);
	bound = (p == 1 ? bound : start);
	k = (p == 1 ? i < bound : i > bound);
	while (k)
	{
		k = 0;
		while (k < set_len && s1[i] != set[k])
			k++;
		if (k == set_len)
			break ;
		i = (p == 1 ? i + 1 : i - 1);
		k = (p == 1 ? i < bound : i > bound);
	}
	return (i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int start;
	int end;

	if (!s1 || !set)
		return (0);
	start = st_en(s1, set, 1, 0);
	end = st_en(s1, set, -1, start);
	return (ft_substr(s1, start, end - start + 1));
}
