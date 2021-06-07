/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_spliting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 19:58:24 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 11:37:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_append_word(t_token **tokens, t_token *token, int i)
{
	int		len;
	t_token	*tmp;

	len = 0;
	while (token->str[i + len])
	{
		if (token->quotes[i + len] == UNQUOTED && ft_isifs(token->str[i + len]))
			break ;
		len++;
	}
	tmp = ft_token_create(token->str + i, token->quotes + i, len, token->type);
	if (!tmp)
	{
		ft_token_clear(tokens);
		return (-EMAF);
	}
	ft_token_addback(tokens, tmp);
	return (len);
}

t_token	*ft_word_spliting(t_token *token, int *error)
{
	int		i;
	int		len;
	t_token	*ret;

	i = 0;
	ret = 0;
	len = 0;
	*error = 0;
	while (len >= 0 && token->str[i])
	{
		if (token->quotes[i] == UNQUOTED && ft_isifs(token->str[i]))
			i += ft_traverse_ifs(token->str + i, token->quotes + i);
		if (!token->str[i])
			break ;
		len = ft_append_word(&ret, token, i);
		i += len;
	}
	if (len < 0)
		*error = EMAF;
	ft_token_del(token);
	return (ret);
}
