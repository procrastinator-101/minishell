/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_backslash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 12:59:23 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 10:11:52 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lexer.h"

int	ft_process_backslash(char *str, t_metadata *meda, int index)
{
	meda[index++].uq = 1;
	if (!str[index])
		return (-ENCQ);
	meda[index++].es = 1;
	return (index);
}
