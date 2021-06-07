/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 18:04:37 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 14:16:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static t_token	*ft_handle_parameter_expansion(t_token *token, int *error)
{
	*error = ft_parameter_expansion(token);
	if (*error)
	{
		ft_token_del(token);
		return (0);
	}
	if (!token->str)
	{
		if (ft_isrdc_operand(token))
			*error = EURDC;
		ft_token_del(token);
		return (0);
	}
	return (token);
}

static int	ft_handle_rdc_operand(t_token *token)
{
	free(g_shell.rdc_operand);
	g_shell.rdc_operand = 0;
	if (ft_isrdc_operand(token))
	{
		g_shell.rdc_operand = ft_strdup(token->str);
		if (!g_shell.rdc_operand)
			return (EMAF);
	}
	return (0);
}

t_token	*ft_expand_token(t_token *token, int *error)
{
	int		ret;

	*error = 0;
	ret = ft_isparameter_expandable(token);
	if (ret)
	{
		*error = ft_handle_rdc_operand(token);
		if (*error)
			return (token);
		token = ft_handle_parameter_expansion(token, error);
		if (*error || !token)
			return (token);
		if (token->str[0])
		{
			token = ft_word_spliting(token, error);
			if (*error)
				return (token);
			if (ft_isrdc_operand(token) && token->next)
				*error = EURDC;
		}
	}
	return (ft_quote_removal(token));
}
