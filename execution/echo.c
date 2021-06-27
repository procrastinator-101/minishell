/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:40:22 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/12 12:40:25 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	echo_built(t_scmd *scmd)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	while (scmd->args[i] && scmd->args[i][0] == '-' && scmd->args[i][1] == 'n')
	{
		j = 1;
		while (scmd->args[i][j] && scmd->args[i][j] == 'n')
			j++;
		if (scmd->args[i][j] != '\0')
			break ;
		i++;
		n = 1;
	}
	while (scmd->args[i])
	{
		ft_putstr_fd(scmd->args[i], 1);
		if (scmd->args[++i])
			ft_putstr_fd(" ", 1);
	}
	if (n == 0)
		ft_putstr_fd("\n", 1);
	return (0);
}
