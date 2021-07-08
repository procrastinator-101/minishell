/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_ifs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:50:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/08 19:39:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_traverse_ifs(char *str, t_metadata *meda)
{
	int	i;

	i = 0;
	while (str[i] && !ft_isquoted(str[i], meda[i]) && ft_isifs(str[i]))
	{
		if (meda[i].va)
			return (i);
		i++;
	}
	return (i);
}
