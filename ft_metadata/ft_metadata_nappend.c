/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata_nappend.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:53:39 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 11:19:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_metadata.h"

t_metadata	*ft_metadata_nappend(t_metadata *m1, t_metadata *m2, size_t n)
{
	size_t		len1;
	size_t		len2;
	t_metadata	*ret;

	len1 = 0;
	while (m1 && m1[len1].holder != EOMD)
		len1++;
	len2 = 0;
	while (len2 < n && m2[len2].holder != EOMD)
		len2++;
	ret = malloc((len1 + len2 + 1) * sizeof(char));
	if (!ret)
		free(m1);
	if (!ret)
		return (0);
	ret[len1 + len2].holder = EOMD;
	while (len2--)
		ret[len1 + len2] = m2[len2];
	while (len1--)
		ret[len1] = m1[len1];
	free(m1);
	return (ret);
}
