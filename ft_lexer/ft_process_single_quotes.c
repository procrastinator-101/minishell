/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_single_quotes.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:38:18 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:12:05 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_single_quotes(char *str, t_metadata *meda, int index)
{
	meda[index++].uq = 1;
	while (str[index] && str[index] != '\'')
		meda[index++].sq = 1;
	if (!str[index])
		return (-ENCQ);
	meda[index++].uq = 1;
	return (index);
}
