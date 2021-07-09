/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expand_cstring.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 10:52:55 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 14:15:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static char	*ft_get_cstring(char *str, t_metadata *meda, int *len)
{
	int		i;

	i = 2;
	while (str[i] && (str[i] != '\'' || !meda[i].uq))
		i++;
	*len = i;
	return (ft_strndup(str + 2, i - 2));
}

char	*ft_expand_cstring(char *str, t_metadata *meda, int *len)
{
	int		i;
	int		error;
	char	*ret;
	char	*cstring;

	ret = ft_strdup("");
	if (!ret)
		return (0);
	cstring = ft_get_cstring(str, meda, len);
	if (!cstring)
		free(ret);
	if (!cstring)
		return (0);
	i = 0;
	error = 0;
	while (error >= 0 && cstring[i])
	{
		if (cstring[i] == '\\')
			error = ft_append_escape_sequence(&ret, cstring + i);
		else
			error = ft_append_normal_sequence(&ret, cstring + i);
		i += error;
	}
	free(cstring);
	return (ret);
}
