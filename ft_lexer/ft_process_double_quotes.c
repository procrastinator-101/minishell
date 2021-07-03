/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_double_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:49:24 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/03 19:13:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_double_quotes(char *str, t_metadata *meda, int index)
{
	meda[index].uq = 1;
	while (str[++index] && str[index] != '"')
		meda[index].dq = 1;
	if (!str[index])
		return (-ENCQ);
	meda[index++].uq = 1;
	return (index);
}
