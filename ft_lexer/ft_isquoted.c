/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isquoted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 08:53:37 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/03 19:14:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isquoted(char c, t_metadata meda)
{
	if (c == '$')
	{
		if (meda.uq || meda.dq)
			return (0);
		return (1);
	}
	return (!meda.uq);
}
