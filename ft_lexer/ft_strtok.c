/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 13:32:46 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:12:51 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

t_token	*ft_strtok(char *str, t_metadata *meda, char **delimiters, int *offset)
{
	int		i;
	int		type;
	int		start;

	type = ENDL;
	start = *offset;
	i = start - 1;
	while (str[++i])
	{
		if (!meda[i].uq)
			continue ;
		type = ft_find_delimiter(str + i, delimiters);
		if (type == WORD)
			continue ;
		*offset = i;
		if (start < i)
			return (ft_token_create(str + start, meda + start, i - start, \
				WORD));
		i += ft_strlen(delimiters[type]);
		break ;
	}
	*offset = i;
	return (ft_token_create(str + start, meda + start, i - start, type));
}
