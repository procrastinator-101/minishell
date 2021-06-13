/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_double_quote_construct.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:56:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 19:13:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_double_quote_construct(t_token *token, char *str, char *quotes)
{
	if (quotes[0] == UNQUOTED)
		return (1);
	token->str = ft_strnappend(token->str, str, 1);
	if (!token->str)
		return (-EMAF);
	token->quotes = ft_strnappend(token->quotes, quotes, 1);
	if (!token->quotes)
		return (-EMAF);
	return (1);
}
