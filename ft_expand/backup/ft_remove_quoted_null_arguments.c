/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quoted_null_arguments.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 16:24:09 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 16:43:59 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

static char	*ft_copy_non_null_arguments(char *src, int len, int *error)
{
	int		i;
	char	*dst;

	dst = malloc((len + 1) * sizeof(char));
	if (!dst)
	{
		free(src);
		*error = EMAF;
		return (0);
	}
	i = -1;
	len = 0;
	while (src[++i])
	{
		if (src[i] == '\'' && src[i] == '\'')
			i++;
		else
			dst[len++] = src[i];
	}
	dst[i] = 0;
	free(src);
	return (dst);
}

char	*ft_remove_quoted_null_arguments(char *src, int *error)
{
	int		i;
	int		len;

	i = -1;
	len = 0;
	*error = 0;
	while (src[++i])
	{
		if (src[i] == '\'' && src[i] == '\'')
			i++;
		else
			len++;
	}
	return (ft_copy_non_null_arguments(src, len, error));
}
