/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata_ndup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:32:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:50:57 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_metadata.h"

t_metadata	*ft_metadata_ndup(t_metadata *meda, size_t n)
{
	size_t	i;
	t_metadata	*ret;

	i = 0;
	while (i < n && meda[i].holder != EOMD)
		i++;
	ret = malloc((i + 1) * sizeof(t_metadata));
	if (!ret)
		return (0);
	ret[i].holder = EOMD;
	while (i--)
		ret[i] = meda[i];
	return (ret);
}
