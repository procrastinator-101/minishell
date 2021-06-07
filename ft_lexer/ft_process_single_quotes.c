/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_single_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:38:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/03 10:58:12 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_single_quotes(char *line, char *quotes, int index)
{
	quotes[index++] = UNQUOTED;
	while (line[index] && line[index] != '\'')
		quotes[index++] = SINGLE_QUOTED;
	if (!line[index])
		return (-ENCQ);
	quotes[index++] = UNQUOTED;
	return (index);
}
