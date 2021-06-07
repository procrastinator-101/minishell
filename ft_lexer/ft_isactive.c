/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:27:55 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 13:49:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_isactive(char c, char quote)
{
	if (c == '$' || c == '`')
	{
		if (quote == UNQUOTED || quote == DOUBLE_QUOTED)
			return (1);
		return (0);
	}
	return (quote == UNQUOTED);
}
