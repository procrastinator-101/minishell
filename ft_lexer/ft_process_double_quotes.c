/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_double_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:49:24 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 16:26:01 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_double_quotes(char *line, char *quotes, int index)
{
	char	c;

	quotes[index] = UNQUOTED;
	while (line[++index] && line[index] != '"')
	{
		if (line[index] == '\\')
		{
			c = line[index + 1];
			if (c == '\\' || c == '$' || c == '`' || c == '"' || c == '\n')
			{
				quotes[index] = UNQUOTED;
				quotes[++index] = ESCAPED;
			}
			else
				quotes[index] = DOUBLE_QUOTED;
		}
		else
			quotes[index] = DOUBLE_QUOTED;
	}
	if (!line[index])
		return (-ENCQ);
	quotes[index++] = UNQUOTED;
	return (index);
}
