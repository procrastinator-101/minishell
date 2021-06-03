/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_double_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:49:24 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 16:02:10 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_process_double_quotes(char *line, char *quotes, int index)
{
	char	c;

	quotes[index++] = NON_QUOTED;
	while (line[index] && line[index] != '"')
	{
		if (line[index] == '`' || line[index] == '$')
			quotes[index] = NON_QUOTED;
		else if (line[index] == '\\')
		{
			c = line[index + 1];
			if (c == '\\' || c == '$' || c == '`' || c == '"')
			{
				quotes[index] = NON_QUOTED;
				quotes[++index] = QUOTED;
			}
			else
				quotes[index] = QUOTED;
		}
		else
			quotes[index] = QUOTED;
		index++;
	}
	if (!line[index])
		return (ENCQ);
	quotes[index++] = NON_QUOTED;
	return (index);
}
