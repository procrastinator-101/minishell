/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_protect_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:55:22 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/07 17:55:24 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	*checkalloc(char *str)
{
	if (str)
		return (str);
	print_error("MALLOC", strerror(errno), 1);
	exit(1);
}

char	*catch_null_ordup(char *str)
{
	if (str)
		return (checkalloc(ft_strdup2(str)));
	return (str);
}

char	*ft_strdup2(const char *src)
{
	int		s;
	char	*dest;
	int		i;

	if (src == NULL)
		return (checkalloc(ft_strdup2("")));
	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	dest = (char *)malloc(sizeof(dest) * (s + 1));
	if (!dest)
		return (NULL);
	while (i <= s)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
