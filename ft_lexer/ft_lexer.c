/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:14:08 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:59:39 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*ft_lexer(char *line, int size, int *error)
{
	t_token		*tokens;
	t_metadata	*meda;

	*error = 0;
	meda = ft_process_quotes(line, size, error);
	if (*error)
		return (0);
	tokens = ft_tokenise(line, meda, g_shell.delimiters, error);
	free(meda);
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
