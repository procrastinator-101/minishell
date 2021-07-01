/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:44:26 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/12 12:44:27 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	check_options(t_scmd *scmd)
{
	int	i;

	i = 1;
	while (scmd->args[i])
	{
		if (scmd->args[i][0] == '-')
		{
			ft_display_error_msg(0);
			ft_putstr_fd("pwd: Options not allowed\n", 2);
			g_shell.scmd_status = 1;	// to check
			return (1);
		}
		i++;
	}
	return (0);
}

int	pwd_built(t_scmd *scmd)
{
	char	*pwd;

	if (check_options(scmd) == 1)
		return (1);
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		pwd = get_env_value("PWD");
	}
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
	free(pwd);
	return (0);
}
