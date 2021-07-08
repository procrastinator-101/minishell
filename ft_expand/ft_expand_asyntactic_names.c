/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_asyntactic_names.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 19:07:20 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:36:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_asyntactic_names(t_token *token, char *str, t_metadata *meda)
{
	token->str = ft_strnappend(token->str, str, 1);
	if (!token->str)
		return (-EMAF);
	token->meda = ft_metadata_nappend(token->meda, meda, 1);
	if (!token->meda)
		return (-EMAF);
	return (1);
}
