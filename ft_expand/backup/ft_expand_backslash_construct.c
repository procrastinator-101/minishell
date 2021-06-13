/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_backslash_construct.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 16:11:34 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 16:14:46 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_backslash_construct(t_token *token, char *str, char *quotes)
{
	token->str = ft_strnappend(token->str, str, 1);
	if (!token->str)
		return (-EMAF);
	token->quotes = ft_strnappend(token->quotes, quotes, 1);
	if (!token->quotes)
		return (-EMAF);
	return (1);
}	
