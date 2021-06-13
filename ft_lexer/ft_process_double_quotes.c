/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_double_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:49:24 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:12:13 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_double_quotes(char *str, t_metadata *meda, int index)
{
	char	c;

	meda[index].uq = 1;
	while (str[++index] && str[index] != '"')
	{
		if (str[index] == '\\')
		{
			c = str[index + 1];
			if (c == '\\' || c == '$' || c == '`' || c == '"' || c == '\n')
			{
				meda[index].uq = 1;
				meda[++index].es = 1;
			}
			else
				meda[index].dq = 1;
		}
		else
			meda[index].dq = 1;
	}
	if (!str[index])
		return (-ENCQ);
	meda[index++].uq = 1;
	return (index);
}
