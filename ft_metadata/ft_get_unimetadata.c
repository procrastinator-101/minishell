/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_unimetadata.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:00:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:00:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_metadata.h"

t_metadata	*ft_get_unimetadata(size_t size, int quote, int va, int expns)
{
	size_t		i;
	t_metadata	*ret;
	t_metadata	meda;

	ret = malloc(size * sizeof(t_metadata));
	if (!ret)
		return (0);
	meda.holder = 0;
	if (quote == SINGLE_QUOTED)
		meda.sq = 1;
	else if (quote == DOUBLE_QUOTED)
		meda.dq = 1;
	else if (quote == ESCAPED)
		meda.es = 1;
	else if (quote == UNQUOTED)
		meda.uq = 1;
	meda.va = va;
	meda.ex = expns;
	i = 0;
	while (i < size - 1)
		ret[i++] = meda;
	ret[i].holder = EOMD;
	return (ret);
}
