/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:49:53 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 15:25:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	s1_len = 0;
	s2_len = 0;
	while (s1[s1_len])
		s1_len++;
	while (s2[s2_len])
		s2_len++;
	ptr = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	ptr[s1_len + s2_len] = 0;
	while (s2_len--)
		ptr[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		ptr[s1_len] = s1[s1_len];
	return (ptr);
}
