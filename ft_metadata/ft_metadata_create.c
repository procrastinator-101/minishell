/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metadata_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 10:27:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 11:39:06 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_metadata.h"

t_metadata	*ft_metadata_create(size_t size)
{
	t_metadata	*meda;

	meda = malloc(size * sizeof(t_metadata));
	if (!meda)
		return (0);
	while (size--)
		meda[size].holder = 0;
	return (meda);
}
