/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_normal_construct.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:16:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 18:37:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_normal_construct(t_token *token, char *str, char *quotes)
{
	int		len;
	int		ret;
	int		error;
	char	*ptr;

	ptr = ft_substitute_parameter(str + 1, quotes[0], &error, &ret);
	if (error)
		return (-EMAF);
	if (!ptr)
		return (ret + 1);
	len = ft_strlen(ptr);
	token->str = ft_strnappend(token->str, ptr, len);
	free(ptr);
	if (!token->str)
		return (-EMAF);
	ptr = ft_get_uniquotes(len + 1, quotes[0]);
	if (!ptr)
		return (-EMAF);
	token->quotes = ft_strnappend(token->quotes, ptr, len);
	free(ptr);
	if (!token->quotes)
		return (-EMAF);
	return (ret + 1);
}
