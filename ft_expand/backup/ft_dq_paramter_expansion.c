/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dq_paramter_expansion.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 14:13:22 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/04 10:52:42 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_dq_paramter_expansion(char *src, char *src_quotes, char **dst, \
	char **dst_quotes)
{
	int	ret;
	int	error;

	ret = 1;
	if (src[1] == '\'' || src[1] == '\\')
	{
		*dst = ft_strndup(src, 2);
		if (!*dst)
			return (-EMAF);
		*dst_quotes = ft_strndup(src_quotes, 2);
	}
	else
	{
		*dst = ft_substitute_parameter(src + 1, src_quotes[1], &error, &ret);
		if (error)
			return (-error);
		*dst_quotes = ft_get_uniquotes(ft_strlen(*dst, src_quotes[1]));
	}
	if (!*dst_quotes)
		free(*dst);
	if (!*dst_quotes)
		return (-EMAF);
	return (ret + 1);
}
