/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 12:46:01 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/12 12:46:04 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	ft_set_isenv(char *name, int isenv)
{
	t_envp *env;

	env = g_shell.envp;
	while (env)
	{
		if (ft_strcmp(name, env->name) == 0)
		{
			env->isenv = isenv;
			return ;
		}
		env = env->next;
	}
}

int	ft_isenv(char *name)
{
	t_envp *env;

	env = g_shell.envp;
	while (env)
	{
		if (ft_strcmp(name, env->name) == 0)
		{
			return (env->isenv);
		}
		env = env->next;
	}
	return (2);
}

char	*get_env_value(char *name)
{
	t_envp *env;

	env = g_shell.envp;
	while (env)
	{
		if (ft_strcmp(name, env->name) == 0)
		{
			return (env->value);
		}
		env = env->next;
	}
	return ("");
}

int	env_built(t_scmd *scmd)
{
	t_envp *env;

	if (tablen(scmd->args) != 1)
	{
		ft_display_error_msg(0);
		ft_putstr_fd("env: No options or arguments allowed\n", 2);
		g_shell.scmd_status = 1;
		return (1);
	}
	env = g_shell.envp;
	while (env)
	{
		if (env->isenv == 1 && env->value)
		{
			ft_putstr_fd(env->name, 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd(env->value, 1);
			ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
	return (0);
}
