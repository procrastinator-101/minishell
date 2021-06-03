/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:32:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 11:00:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*ft_strtok(char *line, char *quotes, char **delimiters, int *offset)
{
	int		i;
	int		start;
	int		type;

	start = *offset;
	i = start - 1;
	type = ENDL;
	while (line[++i])
	{
		if (quotes[i] != UNQUOTED)
			continue ;
		type = ft_find_delimiter(line + i, delimiters);
		if (type == WORD)
			continue ;
		*offset = i;
		if (start < i)
			return (ft_token_create(line + start, quotes + start, i - start, \
				WORD));
		i += ft_strlen(delimiters[type]);
		break ;
	}
	*offset = i;
	return (ft_token_create(line + start, quotes + start, i - start, type));
}
