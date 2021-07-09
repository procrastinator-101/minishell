/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_expansion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 10:29:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:58:38 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_parameter_expansion(t_token *token)
{
	int			i;
	int			ret;
	char		*str;
	t_metadata	*meda;

	i = 0;
	ret = 0;
	str = token->str;
	meda = token->meda;
	token->str = 0;
	token->meda = 0;
	while (ret >= 0 && str[i])
	{
		if (str[i] == '$' && !ft_isquoted(str[i], meda[i]))
			ret = ft_manage_active_expansion(token, str + i, meda + i);
		else
			ret = ft_manage_passive_expansion(token, str + i, meda + i);
		i += ret;
	}
	ret = -ret;
	if (ret < 0)
		ret = 0;
	free(str);
	free(meda);
	return (ret);
}
