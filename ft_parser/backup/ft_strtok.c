/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/27 12:13:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_token	*ft_get_word(char *line, char *quotes, char **delimiters, int *offset)
{
	int	end;

	end = 0;
	while (line[*offset + end])
	{
		if (quotes[*offset + end] == QUOTED)
			end++;
		else if (ft_find_delimiter(line + *offset + end, delimiters) == WORD)
			end++;
		else
			break ;
	}
	int start = *offset;
	*offset += end;
	return (ft_token_create(line + start, quotes + start, end, WORD));
}

static t_token	*ft_get_sep(char *delimiter, char *quotes, char type, int *offset)
{
	int	len;
	int	start;

	len = ft_strlen(delimiter);
	start = *offset;
	*offset += len;
	return (ft_token_create(delimiter, quotes + start, len, type));
}

int	ft_traverse_spaces(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	return (i);
}

t_token	*ft_strtok(char *line, char *quotes, char **delimiters, int *offset)
{
	char	type;
	int		idx;
	int		start;

	printf("============================================================\n");
	start = *offset + ft_traverse_spaces(line + *offset);
	idx = start - 1;
	type = ENDL;
	while (line[++idx])
	{
		if (line[idx] == QUOTED)
			continue ;
		type = ft_find_delimiter(line + idx, delimiters);
		printf("type = %d\nline = %s\n", type, line + idx);
		if (type == WORD)
			continue ;
		*offset = idx;
		if (type == BLANK || start < idx)
			return (ft_token_create(line + start, quotes + start, idx - start, WORD));
		idx = ft_strlen(delimiters[type]);
		*offset += idx;
		return (ft_token_create(delimiters[type], quotes + idx, idx, type));
	}
	*offset = idx;
	return (ft_token_create(line + start, quotes + start, idx - start, type));
}

/*
{
	*offset = ft_traverse_spaces(line + *offset);
	while ()
	{
		if (quoted)
			continue ;
		if (word)
			continue ;
		if (blank)
			return (word);
		if (type)
			return (type);
	}
}
*/

/*
	while (line[*offset])
	{
		if (quotes[*offset] == QUOTED)
			return (ft_get_word(line, quotes, delimiters, offset));
		type = ft_find_delimiter(line + *offset, delimiters);
		if (type == WORD)
			return (ft_get_word(line, quotes, delimiters, offset));
		if (type != BLANK)
			return (ft_get_sep(delimiters[type], quotes, type, offset));
		(*offset)++;
	}
	return (ft_token_create(line + *offset, quotes + *offset, 0, ENDL));
*/
