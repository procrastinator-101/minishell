/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _exit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 19:09:38 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/14 16:42:19 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_atol_error(char *str)
{
	print_error_3("exit", str, "numeric argument required", 255);
	exit(255);
}

static long	ft_atol(char *str, int i)
{
	long	r;
	long	sg;

	sg = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sg = sg * (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_atol_error(str);
		else if (r <= ((LONG_MAX - (str[i] - 48)) / 10)
			|| (r <= ((LONG_MAX - (str[i] - 48) + 1) / 10)
				&& sg == -1))
			r = r * 10 + (str[i] - 48);
		else
			ft_atol_error(str);
		i++;
	}
	return (r * sg);
}

int	exit_built(t_scmd *scmd)
{
	long	ret;

	if (!scmd->previous && !scmd->next)
		ft_putendl_fd("exit", STDOUT_FILENO);
	if (tablen(scmd->args) <= 2)
	{
		if (scmd->args[1])
		{
			if (!ft_isnumber(scmd->args[1]))
				ft_atol_error(scmd->args[1]);
			ret = ft_atol(scmd->args[1], 0);
			exit(ret);
		}
		else
			exit(g_shell.pipeline_status);
	}
	else
	{
		if (!ft_isnumber(scmd->args[1]))
			ft_atol_error(scmd->args[1]);
		ret = ft_atol(scmd->args[1], 0);
		print_error("exit", "too many arguments", 1);
	}
	return (1);
}
