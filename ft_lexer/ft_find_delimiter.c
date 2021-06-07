/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_delimiter.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:09:25 by yarroubi          #+#    #+#             */
/*   Updated: 2021/05/29 12:46:51 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_find_delimiter(char *str, char **delimiters)
{
	int	i;

	i = 0;
	while (++i < DELIM_SIZE)
	{
		if (i < SEMICOLON)
		{
			if (!ft_strncmp(str, delimiters[i], 2))
				return (i);
		}
		else
		{
			if (*str == delimiters[i][0])
				return (i);
		}
	}
	return (WORD);
}
