/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 16:18:00 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_token	*ft_tokenise(char *line, char *quotes, char **delimiters)
{
	int		i;
	int		type;
	int		start;
	t_token	*token;
	t_token	*tokens;

	i = -1;
	start = 0;
	token = 0;
	tokens = 0;
	while (line[++i])
	{
		if (quotes[i] == QUOTED)
			continue ;
		type = ft_find_str(line + i, delimiters);
		if (type < 0)
			continue ;
		token = ft_token_create(line + start, quotes + start, i, WORD);
		if (!token)
			break ;
		ft_token_addback(tokens, token);
		if (type == BLANK)
			continue ;
		token = ft_token_create(delimiters[type], NULL, MAX_DELIM, type);
		if (!token)
			break ;
		ft_token_addback(tokens, token);
		start = i + 1;
	}
	if (!token)
		ft_token_clear(&tokens);
	return (tokens);
}
