/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 11:35:31 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/26 18:04:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static t_token	*ft_get_tokens(t_text text, char *delimiters, int border[2])
{
	int		type;
	t_token	*token;
	t_token	*tokens;

	tokens = 0;
	type = ft_find_str(text.line + border[1], delimiters);
	if (type < 0)
		return ;
	if (border[0] < border[1])
	{
		token = ft_token_create(text, border[0], border[1], WORD);
		if (!token)
			return ;
		ft_token_addback(&tokens, token);
	}
	if (type == BLANK)
	{
		border[0] += ft_traverse_spaces(text->line + border[1]);
		return ;
	}
	text.line = delimiter[type];
	token = ft_token_create(text, 0, MAX_DELIM, type);
	if (token)
		ft_token_addback(tokens, token);
	else
		ft_token_clear(&tokens);
	border[0] = ft_strlen(delimiter[type]);
	return (tokens);
}

t_token	*ft_tokenise(char *line, char *quotes, char **delimiters)
{
	int		i;
	int		border[2];
	t_token	*token;
	t_token	*tokens;

	i = -1;
	start = 0;
	token = 0;
	tokens = 0;
	while (++i < text->size)
	{
		if (text->quotes[i] == QUOTED)
			continue ;
		token = ft_get_tokens(text, delimiters, start, &i);
		if (!token)
			break ;
		ft_token_addback(tokens, token);
		i = border[0];
	}
	if (!token)
		ft_token_clear(&tokens);
	return (tokens);
}
