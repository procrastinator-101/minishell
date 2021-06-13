/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_quoted_null_arguments.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 15:16:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 16:20:40 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static char	*ft_remove_null_argument(char *src, char *dst, int start, int end)
{
	char	*str;
	char	*tmp;

	if (dst && start == end)
		return (dst);
	str = ft_strndup(src + start, end - start);
	if (!str)
	{
		free(dst);
		free(src);
		return (0);
	}
	if (!dst)
		return (str);
	tmp = dst;
	dst = ft_strjoin(tmp, str);
	free(tmp);
	free(str);
	if (!dst)
	{
		free(src);
		return (0);
	}
	return (dst);
}

char	*ft_remove_quoted_null_arguments(char *src, int *error)
{
	int		i;
	int		start;
	char	*dst;

	i = 0;
	dst = 0;
	start = 0;
	*error = 0;
	while (src[i])
	{
		if (src[i] == '\'' && src[i] == '\'')
		{
			dst = ft_remove_null_argument(src, dst, start, i);
			if (!dst)
			{
				*error = EMAF;
				return (0);
			}
			start = i + 2;
			i++;
		}
		i++;
	}
	free(src);
	return (dst);
}
