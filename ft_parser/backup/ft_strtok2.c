/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/27 10:04:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

//create word token : prev token == op -> cmd
//					: prev token == mc -> arg
			//create operator or metacharcater token
t_token	*ft_strtok(char *line, char *quotes, char **delimiters, int *offset)
{
	int		idx;
	int		start;
	char	type;

	start = *offset;
	idx = start - 1;
	printf("============================================================\n");
	while (line[++idx])
	{
		if (quotes[idx] == QUOTED)
			continue ;
		printf("start = %d\n", start);
		type = ft_find_delimiter(line + idx, delimiters);
		printf("type = %d\n", type);
		if (type == WORD)
			continue ;
		if (type == BLANK)
		{
			if (start == idx)
			{
				start = idx + 1;
				continue ;
			}
		}
		*offset = idx;
		if (start == idx)
			return (ft_token_create(delimiters[type], quotes, \
				ft_strlen(delimiters[type]), type));
		break ;
	}
	*offset = idx;
	if (start < idx)
		return (ft_token_create(line + start, quotes + start, idx - start, WORD));
	return (ft_token_create(line + start, quotes + start, idx, ENDL));
}
