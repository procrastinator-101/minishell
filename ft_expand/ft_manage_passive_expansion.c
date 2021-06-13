/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_passive_expansion.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 12:51:53 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 16:41:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_manage_passive_expansion(t_token *token, char *str, t_metadata *meda)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != '$' || ft_isquoted(str[i], meda[i])))
		i++;
	token->str = ft_strnappend(token->str, str, i);
	if (!token->str)
		return (-EMAF);
	token->meda = ft_metadata_nappend(token->meda, meda, i);
	if (!token->meda)
		return (-EMAF);
	return (i);
}
