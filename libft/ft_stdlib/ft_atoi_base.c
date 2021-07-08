/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:47:06 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/04 16:09:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	ft_get_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (!str[i])
		return (-1);
	return (i);
}

int	ft_atoi_base(const char *str, char *base)
{
	int	i;
	int	sp;
	int	ret;
	int	index;
	int	base_nbr;

	sp = 0;
	base_nbr = ft_strlen(base);
	while (ft_isspace(str[sp]))
		sp++;
	i = sp;
	if (str[sp] != '-' && str[sp] != '+')
		i--;
	ret = 0;
	while (str[++i])
	{
		index = ft_get_index(base, str[i]);
		if (index < 0)
			break ;
		ret = ret * base_nbr + index;
	}
	if (str[sp] == '-')
		return (-ret);
	return (ret);
}
