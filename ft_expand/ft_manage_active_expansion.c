/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_active_expansion.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:51:01 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/09 11:42:03 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_manage_active_expansion(t_token *token, char *str, t_metadata *meda)
{
	if (meda[0].uq)
	{
		if (str[1] == '\'')
			return (ft_expand_singlequote_construct(token, str, meda));
		else if (str[1] == '"')
			return (1);
	}
	if (token->type != HDOC_ROPERAND)
	{
		if (ft_is_special_parameter(str[1]))
			return (ft_expand_special_parameters(token, str, meda));
		else if (str[1] == '_' || ft_isalpha(str[1]))
			return (ft_expand_normal_construct(token, str, meda));
	}
	return (ft_expand_asyntactic_names(token, str, meda));
}
