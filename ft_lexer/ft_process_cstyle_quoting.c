/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_cstyle_quoting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:11 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 11:53:47 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_cstyle_quoting(char *line, char *quotes, int index)
{
	quotes[index++] = UNQUOTED;
	if (!line[index] || line[index] != '\'')
		return (index);
	quotes[index++] = UNQUOTED;
	while (line[index] && line[index] != '\'')
	{
		if (line[index] == '\\' && line[index + 1] == '\'')
			quotes[index++] = SINGLE_QUOTED;
		quotes[index++] = SINGLE_QUOTED;
	}
	if (!line[index])
		return (-ENCQ);
	quotes[index++] = UNQUOTED;
	return (index);
}
