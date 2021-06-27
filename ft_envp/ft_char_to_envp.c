/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 18:36:17 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:38:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_envp.h"

t_envp	*ft_char_to_envp(char *str, int *error, int isenv)
{
	char	*name;
	char	*value;
	char	*equal;
	t_envp	*envp;

	*error = EMAF;
	equal = ft_strchr(str, '=');
	name = ft_strndup(str, equal - str);
	if (!name)
		return (0);
	value = ft_strdup(equal + 1);
	if (!value)
	{
		free(name);
		return (0);
	}
	envp = ft_envp_create(name, value, isenv);
	if (!envp)
	{
		free(name);
		free(value);
		return (0);
	}
	*error = 0;
	return (envp);
}
