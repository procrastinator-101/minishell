/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by_delimiter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:27:57 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 15:51:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_update_segments(t_list **segments, char *str, size_t len)
{
	char	*ptr;
	t_list	*node;

	ptr = ft_strndup(str, len);
	node = ft_lstnew(ptr);
	if (!node || !ptr)
	{
		if (!node)
			free(ptr);
		ft_lstclear(segments, free);
		return ;
	}
	ft_lstadd_back(segments, node);
}

t_list	*ft_split_by_delimiter(char *str, char *quotes, char delimiter)
{
	int		i;
	int		start;
	t_list	*segments;

	i = -1;
	start = 0;
	segments = 0;
	while (str[++i])
	{
		if (str[i] == delimiter && quotes[i] == NON_QUOTED)
		{
			ft_update_segments(&segments, str + start, i - start);
			if (!segments)
				return (0);
			start = i + 1;
		}
	}
	ft_update_segments(&segments, str + start, i - start);
	return (segments);
}
