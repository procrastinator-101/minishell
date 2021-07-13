/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 21:33:39 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/13 10:38:11 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support_functions.h"
#include <stdio.h>
static size_t	delimc(char const *s, char c, size_t *len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	*len = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			while (s[i] != c && s[i] != '\0')
				i++;
			n++;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (n);
}

static	char	**garcol(char **tab, size_t j)
{
	while (--j > 0)
		free(tab[j]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**p;
	size_t	len;
	size_t	start;
	size_t	k;

	if (!s)
		return (NULL);
	k = 0;
	n = delimc(s, c, &len) + 1;
	p = (char **)ft_calloc(n, sizeof(char *));
	if (!p)
		return (0);
	while (k < n - 1)
	{
		while (s[len] == c && s[len])
			len++;
		start = len;
		while (s[len] != c && s[len])
			len++;
		p[k++] = ft_substr(s, start, len - start);
		if (!p[k - 1])
			return (garcol(p, k));
	}
	return (p);
}
