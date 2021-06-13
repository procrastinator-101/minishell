/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_cstyle_quoting.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 10:34:11 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:11:41 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_cstyle_quoting(char *str, t_metadata *meda, int index)
{
	meda[index++].uq = 1;
	if (!str[index] || str[index] != '\'')
		return (index);
	meda[index++].uq = 1;
	while (str[index] && str[index] != '\'')
	{
		if (str[index] == '\\' && str[index + 1] == '\'')
			meda[index++].sq = 1;
		meda[index++].sq = 1;
	}
	if (!str[index])
		return (-ENCQ);
	meda[index++].uq = 1;
	return (index);
}
