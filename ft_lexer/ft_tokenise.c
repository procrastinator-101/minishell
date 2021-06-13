/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenise.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:19:07 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 18:42:53 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*ft_tokenise(char *str, t_metadata *meda, char **delimiters, int *error)
{
	int		start;
	t_token	*token;
	t_token	*tokens;

	start = 0;
	tokens = 0;
	*error = 0;
	token = ft_strtok(str, meda, delimiters, &start);
	while (token && token->type != ENDL)
	{
		ft_token_addback(&tokens, token);
		token = ft_strtok(str, meda, delimiters, &start);
	}
	if (!token)
		*error = EMAF;
	if (!token)
		ft_token_clear(&tokens);
	else
		ft_token_del(token);
	ft_identify_rdc_operands(&tokens);
	return (tokens);
}
