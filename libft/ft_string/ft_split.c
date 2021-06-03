/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 15:47:37 by yarroubi          #+#    #+#             */
/*   Updated: 2019/10/21 17:52:15 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	clear(char **ptr, int size)
{
	int i;

	i = -1;
	while (++i <= size)
		free(ptr[i]);
	free(ptr);
	ptr = 0;
	return (-1);
}

static int	ft_all(char **ptr, char const *s, char c, int p)
{
	int	i;
	int	del;
	int	len_ptr;
	int	size;

	i = -1;
	len_ptr = 0;
	del = 0;
	size = 0;
	while (s[++i])
	{
		len_ptr = (s[i] != c && (del > 0 || i == 0) ? len_ptr + 1 : len_ptr);
		size = (s[i] != c ? size + 1 : size);
		del = (s[i] != c ? 0 : del + 1);
		if (size > 0 && p == 1 && s[i] == c)
			ptr[len_ptr - 1] = ft_substr(s, i - size, size);
		else if (size > 0 && p == 1 && !s[i + 1])
			ptr[len_ptr - 1] = ft_substr(s, i - size + 1, size);
		if ((size > 0 && p == 1 && !ptr[len_ptr - 1]) && (s[i] == c || \
					!s[i + 1]))
			return (clear(ptr, len_ptr - 1));
		size = (s[i] == c ? 0 : size);
	}
	return (len_ptr);
}

char		**ft_split(char const *s, char c)
{
	char	**ptr;
	int		num_words;

	if (!s)
		return (0);
	ptr = 0;
	num_words = ft_all(ptr, s, c, 0);
	ptr = (char **)malloc((num_words + 1) * sizeof(char *));
	if (ptr == 0)
		return (0);
	if (ft_all(ptr, s, c, 1) != -1)
		ptr[num_words] = 0;
	return (ptr);
}
