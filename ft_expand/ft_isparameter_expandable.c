/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isparameter_expandable.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:48:21 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 11:43:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_isparameter_expandable(t_token *token)
{
	int	i;

	i = 0;
	while (token->str[i])
	{
		if (token->str[i] == '$' && !ft_isquoted(token->str[i], token->meda[i]))
			return (1);
		i++;
	}
	return (0);
}
