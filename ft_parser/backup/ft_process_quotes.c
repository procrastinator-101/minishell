/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 11:13:50 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 16:03:31 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

char	*ft_process_quotes(char *line, int size, int *error)
{
	int		i;
	char	*quotes;

	quotes = malloc(size * sizeof(char));
	if (!quotes)
		return (0);
	i = 0;
	while (i < size - 1)
	{
		if (line[i] == '\'')
			i = ft_process_single_quotes(line, quotes, i);
		else if (line[i] == '"')
			i = ft_process_double_quotes(line, quotes, i);
		else if (line[i] == '\\')
			i = ft_process_backslash(line, quotes, i);
		else
			quotes[i++] = NON_QUOTED;
		if (i == ENCQ)
		{
			free(quotes);
			return (0);
		}
	}
	quotes[i] = 0;
	return (quotes);
}
