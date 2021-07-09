/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_single_quote_construct.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:39:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:41:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_singlequote_construct(t_token *token, char *str, t_metadata *meda)
{
	int			ret;
	int			len;
	char		*value;
	t_metadata	*tmp;

	ret = 0;
	value = ft_expand_cstring(str, meda, &ret);
	if (!value)
		return (-EMAF);
	len = ft_strlen(value);
	token->str = ft_strnappend(token->str, value, len);
	free(value);
	if (!token->str)
		return (-EMAF);
	tmp = ft_get_unimetadata(len + 1, SINGLE_QUOTED, meda[0].va, 1);
	if (!tmp)
		return (-EMAF);
	token->meda = ft_metadata_nappend(token->meda, tmp, len);
	free(tmp);
	if (!token->meda)
		return (-EMAF);
	return (ret + 1);
}
