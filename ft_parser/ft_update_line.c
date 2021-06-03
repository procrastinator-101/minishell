/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 08:52:52 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 09:36:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

char	*ft_strnjoin(char *s1, int *s1_size, char *s2, int s2_size)
{
	int		size;
	char	*ret;

	size = 1;
	if (s1)
		size += *s1_size - 1;
	if (s2)
		size += s2_size - 1;
	ret = malloc(size * sizeof(char));
	if (!ret)
	{
		free(s1);
		return (0);
	}
	*s1_size = size;
	while (--s2_size >= 0)
		ret[--size] = s2[s2_size];
	while (--size >= 0)
		ret[size] = s1[size];
	ret[*s1_size - 1] = 0;
	free(s1);
	return (ret);
}
