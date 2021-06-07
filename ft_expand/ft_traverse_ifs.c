/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_traverse_ifs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 20:50:45 by yarroubi          #+#    #+#             */
/*   Updated: 2021/06/05 20:52:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_expand.h"

int	ft_traverse_ifs(char *str, char *quotes)
{
	int	i;

	i = 0;
	while (str[i] && quotes[i] == UNQUOTED && ft_isifs(str[i]))
		i++;
	return (i);
}
