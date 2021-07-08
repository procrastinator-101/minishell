/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnappend.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:10:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 15:00:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support_functions.h"

char	*ft_strnappend(char *s1, char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;
	char	*ret;

	len1 = 0;
	while (s1 && s1[len1])
		len1++;
	len2 = 0;
	while (len2 < n && s2[len2])
		len2++;
	ret = malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		free(s1);
	if (!ret)
		return (0);
	ret[len1 + len2] = 0;
	while (len2--)
		ret[len1 + len2] = s2[len2];
	while (len1--)
		ret[len1] = s1[len1];
	free(s1);
	return (ret);
}
