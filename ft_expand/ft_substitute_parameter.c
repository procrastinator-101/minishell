/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substitute_parameter.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:33:42 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 18:56:17 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

char	*ft_substitute_parameter(char *str, char quote, int *error, int *len)
{
	char	*ret;
	char	*name;
	char	*value;

	*error = 0;
	name = ft_get_name(str, error);
	if (!name)
		return (0);
	*len = ft_strlen(name);
	value = ft_envp_getvalue(g_shell.envp, name);
	free(name);
	if (!value || !ft_strcmp(value, ""))
	{
		if (quote == UNQUOTED)
			return (0);
		ret = ft_strdup("");
	}
	else
		ret = ft_strdup(value);
	if (!ret)
		*error = EMAF;
	return (ret);
}
