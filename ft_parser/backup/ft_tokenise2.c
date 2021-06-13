/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 14:29:00 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static int	ft_update_tokens(t_token **tokens, t_text *text, char **delimiters)
{
	type = ft_find_str(line + i, delimiters);
	if (type > -1)
	{
		if (start < i)
		{
			token = ft_token_append_word(line + start, quotes + start, i, type);
			if (!token)
			{
				ft_token_clear(&tokens);
				return (0);
			}
			ft_token_addback(&tokens, token);
		}
		token = ft_token_create(delimiters[type], NULL, MAX_DELIM, type);
		if (!token)
		{
			ft_token_clear(&tokens);
			return (0);
		}
		ft_token_addback(tokens, token);
		i += ft_strlen(delimiter) - 1;
	}
	return (offset);
}

t_token	*ft_tokenise(char *line, char *quotes, char **delimiters)
{
	int		i;
	int		type;
	int		border[2];
	t_token	*tokens;

	i = -1;
	start = 0;
	tokens = 0;
	while (line[++i])
		ft_update_tokens(&tokens, text, delimiters, i);
	token = ft_token_create(line + start, quotes + start, i, WORD);
	if (!token)
		ft_token_clear(&tokens);
	else
		ft_token_addback(&tokens, token);
	return (tokens);
}
