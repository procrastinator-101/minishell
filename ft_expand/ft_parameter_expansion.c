/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_expansion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:29:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 09:21:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static int	ft_manage_active_expansion(t_token *token, char *str, char *quotes)
{
	if (quotes[0] == UNQUOTED)
	{
		if (str[1] == '\'')
			return (ft_expand_single_quote_construct(token, str, quotes));
		else if (str[1] == '"')
			return (1);
	}
	if (ft_is_special_parameter(str[1]))
		return (ft_expand_special_parameters(token, str, quotes));
	else if (str[1] == '_' || ft_isalpha(str[1]))
		return (ft_expand_normal_construct(token, str, quotes));
	return (ft_expand_asyntactic_names(token, str, quotes));
}

static int	ft_manage_passive_expansion(t_token *token, char *str, char *quotes)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '$' || !ft_isactive(str[i], quotes[i])))
		i++;
	token->str = ft_strnappend(token->str, str, i);
	if (!token->str)
		return (-EMAF);
	token->quotes = ft_strnappend(token->quotes, quotes, i);
	if (!token->quotes)
		return (-EMAF);
	return (i);
}

int	ft_parameter_expansion(t_token *token)
{
	int		i;
	int		ret;
	char	*str;
	char	*quotes;

	i = 0;
	ret = 0;
	str = token->str;
	quotes = token->quotes;
	token->str = 0;
	token->quotes = 0;
	while (ret >= 0 && str[i])
	{
		if (str[i] == '$' && ft_isactive(str[i], quotes[i]))
			ret = ft_manage_active_expansion(token, str + i, quotes + i);
		else
			ret = ft_manage_passive_expansion(token, str + i, quotes + i);
		i += ret;
	}
	ret = -ret;
	if (ret < 0)
		ret = 0;
	free(str);
	free(quotes);
	return (ret);
}
