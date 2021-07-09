/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:53:07 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 13:48:44 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	check_options(t_scmd *scmd)
{
	int	i;

	i = 1;
	while (scmd->args[i])
	{
		if (scmd->args[i][0] == '-' && scmd->args[i][1] != '\0')
		{
			print_error_3(scmd->args[0], scmd->args[i],
				": Options not allowed", 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int	look_for_equal(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '=')
			return (i);
		i++;
	}
	return (0);
}

int	look_for_slach(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '/')
			return (1);
		i++;
	}
	return (0);
}
