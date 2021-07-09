/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getquote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 14:37:36 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:39:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_metadata.h"

char	ft_getquote(t_metadata meda)
{
	if (meda.uq)
		return (UNQUOTED);
	if (meda.dq)
		return (DOUBLE_QUOTED);
	if (meda.sq)
		return (SINGLE_QUOTED);
	return (ESCAPED);
}
