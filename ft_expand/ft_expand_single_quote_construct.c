/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_single_quote_construct.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:39:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/06 15:52:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_single_quote_construct(t_token *token, char *str, char *quotes)
{
	int		ret;
	int		len;
	char	*tmp;
	char	*value;

	ret = 0;
	value = ft_expand_cstring(str, quotes, &ret);
	if (!value)
		return (-EMAF);
	len = ft_strlen(value);
	token->str = ft_strnappend(token->str, value, len);
	free(value);
	if (!token->str)
		return (-EMAF);
	tmp = ft_get_uniquotes(len + 1, SINGLE_QUOTED);
	if (!tmp)
		return (-EMAF);
	token->quotes = ft_strnappend(token->quotes, tmp, len);
	free(tmp);
	if (!token->quotes)
		return (-EMAF);
	return (ret + 1);
}
