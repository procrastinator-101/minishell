/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_removal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 13:45:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 12:04:04 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

t_token	*ft_quote_removal(t_token *token)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (token->str[i])
	{
		if (!ft_isquote(token->str[i]) || !token->meda[i].uq || \
			token->meda[i].ex)
		{
			token->str[j] = token->str[i];
			j++;
		}
		i++;
	}
	if (j < i)
		token->hasquotes = 1;
	token->str[j] = 0;
	return (token);
}
