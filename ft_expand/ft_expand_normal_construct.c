/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_normal_construct.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 15:16:12 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 19:40:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_normal_construct(t_token *token, char *str, t_metadata *meda)
{
	int			len;
	int			ret;
	int			error;
	char		*ptr;
	t_metadata	*tmp;

	ptr = ft_substitute_parameter(str + 1, ft_getquote(meda[0]), &error, &ret);
	if (error)
		return (-EMAF);
	if (!ptr)
		return (ret + 1);
	len = ft_strlen(ptr);
	token->str = ft_strnappend(token->str, ptr, len);
	free(ptr);
	if (!token->str)
		return (-EMAF);
	tmp = ft_get_unimetadata(len + 1, ft_getquote(meda[0]), meda[0].va, 1);
	if (!tmp)
		return (-EMAF);
	token->meda = ft_metadata_nappend(token->meda, tmp, len);
	free(tmp);
	if (!token->meda)
		return (-EMAF);
	return (ret + 1);
}
