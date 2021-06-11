/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:31:38 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/11 11:31:42 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	free_2d(char **tabl)
{
	int i;

	i = 0;
	while (tabl[i])
		free(tabl[i++]);
	free(tabl);
}

int ft_indexchr(const char *s, char a)
{
	int	i;
	int	len;

    len = (int)ft_strlen(s);
	i = -1;
	while (++i < len + 1)
		if (s[i] == a)
			return (i);
	return (i);
}
