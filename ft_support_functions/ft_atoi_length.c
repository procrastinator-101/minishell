/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_length.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 10:31:26 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 10:36:27 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_support_functions.h"

int	ft_atoi_length(char *str, int *len)
{
	int	i;
	int	sp;
	int	ret;

	*len = 0;
	sp = 0;
	while (str[sp] == 32 || (str[sp] > 8 && str[sp] < 14))
		sp++;
	i = sp;
	if (str[sp] == '-' || str[sp] == '+')
		i++;
	ret = 0;
	while (str[i] > 47 && str[i] < 58)
		ret = ret * 10 + (str[i++] - 48);
	*len = i - sp;
	if (str[sp] == '-')
		return (-ret);
	return (ret);
}
