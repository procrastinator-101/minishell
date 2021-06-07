/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 17:36:49 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 18:37:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

char	*ft_get_name(char *str, int *error)
{
	int		i;
	char	*name;

	*error = 0;
	if (str[0] != '_' && !ft_isalpha(str[0]))
		return (0);
	i = 1;
	while (str[i])
	{
		if (str[i] != '_' && !ft_isalnum(str[i]))
			break ;
		i++;
	}
	name = ft_strndup(str, i);
	if (!name)
		*error = EMAF;
	return (name);
}
