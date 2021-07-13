/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _cd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:14:33 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/07 17:17:03 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*safe_dup(char *value)
{
	if (!value)
	{
		ft_display_error_msg(0);
		ft_putstr_fd("cd: error retrieving current directory: getcwd: cannot \
access parent directories: No such file or directory\n", 2);
		return (checkalloc(ft_strjoin(get_env_value("PWD"), "/.")));
	}
	return (value);
}

static int	cd_error(char *path)
{
	ft_display_error_msg(0);
	ft_putstr_fd("cd: ", 2);
	ft_putstr_fd(path, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(strerror(errno), 2);
	g_shell.scmd_status = 1;
	return (1);
}

static int	only_cd(char *path)
{
	DIR	*dd;

	if (path && !path[0])
	{
		ft_display_error_msg(0);
		ft_putstr_fd("cd: HOME not set\n", 2);
	}
	else
	{
		dd = opendir(path);
		if (dd == NULL)
			return (cd_error(path));
		else
		{
			closedir(dd);
			chdir(path);
			ft_envp_setvalue(g_shell.envp, "OLDPWD",
				checkalloc(ft_strdup2(get_env_value("PWD"))));
			ft_envp_setvalue(g_shell.envp, "PWD", safe_dup(getcwd(NULL, 0)));
		}
	}
	return (0);
}

int	cd_built(t_scmd *scmd)
{
	DIR	*dd;

	if (scmd->args[1] == NULL)
		only_cd(get_env_value("HOME"));
	else
	{
		dd = opendir(scmd->args[1]);
		if (dd == NULL)
			return (cd_error(scmd->args[1]));
		else
		{
			closedir(dd);
			chdir(scmd->args[1]);
			ft_envp_setvalue(g_shell.envp, "OLDPWD",
				checkalloc(ft_strdup2(get_env_value("PWD"))));
			ft_envp_setvalue(g_shell.envp, "PWD", safe_dup(getcwd(NULL, 0)));
		}
	}
	return (0);
}
