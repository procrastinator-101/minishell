/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_single_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:38:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/25 15:55:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int	ft_process_single_quotes(char *line, char *quotes, int index)
{
	quotes[index++] = NON_QUOTED;
	while (line[index] && line[index] != '\'')
		quotes[index++] = QUOTED;
	if (!line[index])
		return (ENCQ);
	quotes[index++] = NON_QUOTED;
	return (index);
}
