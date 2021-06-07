/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:14:08 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/01 09:39:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*ft_lexer(char *line, int size, int *error)
{
	char	*quotes;
	t_token	*tokens;

	*error = 0;
	quotes = ft_process_quotes(line, size, error);
	if (*error)
		return (0);
	tokens = ft_tokenise(line, quotes, g_shell.delimiters, error);
	free(quotes);
	if (*error)
		return (0);
	*error = ft_check_syntax(tokens);
	if (*error)
	{
		ft_token_clear(&tokens);
		return (0);
	}
	return (tokens);
}
