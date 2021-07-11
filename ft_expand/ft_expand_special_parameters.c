/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_special_parameters.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 14:53:13 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/11 20:46:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_expand_special_parameters(t_token *token, char *str, t_metadata *meda)
{
	int			len;
	char		*ptr;
	t_metadata	*tmp;

	if (str[1] == '?')
		ptr = ft_itoa(g_shell.scmd_status);
	else
		ptr = ft_strdup(g_shell.argv[0]);
	if (!ptr)
		return (-EMAF);
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
	return (2);
}
