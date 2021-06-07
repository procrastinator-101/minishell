/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:13:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 11:54:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

static char	*ft_set_error(char *quotes, int *error, int type)
{
	free(quotes);
	*error = type;
	return (0);
}

char	*ft_process_quotes(char *line, int size, int *error)
{
	int		i;
	char	*quotes;

	quotes = malloc(size * sizeof(char));
	if (!quotes)
		return (ft_set_error(quotes, error, EMAF));
	i = 0;
	*error = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			i = ft_process_single_quotes(line, quotes, i);
		else if (line[i] == '"')
			i = ft_process_double_quotes(line, quotes, i);
		else if (line[i] == '\\')
			i = ft_process_backslash(line, quotes, i);
		else if (line[i] == '$')
			i = ft_process_cstyle_quoting(line, quotes, i);
		else
			quotes[i++] = UNQUOTED;
		if (i < 0)
			return (ft_set_error(quotes, error, -i));
	}
	quotes[i] = 0;
	return (quotes);
}
