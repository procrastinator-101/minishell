/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_special_parameters.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:53:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/07 10:46:32 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_special_parameters(t_token *token, char *str, char *quotes)
{
	int		len;
	char	*ptr;

	if (str[1] == '?')
		ptr = ft_itoa(g_shell.pipeline_status);
	else
		ptr = ft_strdup(g_shell.argv[0]);
	if (!ptr)
		return (-EMAF);
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
	return (2);
}
