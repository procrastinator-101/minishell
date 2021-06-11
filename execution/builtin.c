/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/03 12:33:55 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/11 11:31:53 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../ft_scmd/ft_scmd.h"
#include "../ft_parser/ft_parser.h"
#include "execution.h"

int	echo_built(t_scmd  *scmd)
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 1;
	while (scmd->args[i] && scmd->args[i][0] == '-'  && scmd->args[i][1] == 'n')
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

char	*get_env_value(char *name)
{
	t_envp *env;

	env = g_env;
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

int	pwd_built(void)
{
	char	*pwd;

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

// int	cd_built(t_scmd  *scmd)
// {
	
// }

int	env_built(void)
{
	t_envp *env;

	env = g_env;
	while (env)
	{
		if (env->isenv == 1)
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

t_envp	*del_env(t_envp *env, t_envp **head)
{
	t_envp	*tmp_ret;

	tmp_ret = env->next;
	if (env->previous)
		env->previous->next = env->next;
	else
		*head = (*head)->next;
	if (env->next)
		env->next->previous = env->previous;
	free(env->name);
	free(env->value);
	free(env);
	return (tmp_ret);
}

int	check_if_exist(t_scmd *scmd, char *name)
{
	int	i;

	i = 1;
	while (scmd->args[i])
	{
		if (ft_strcmp(scmd->args[i], name) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	unset_built(t_scmd *scmd)
{
	t_envp	*head;

	head = g_env;
	while (g_env)
	{
		if (check_if_exist(scmd, g_env->name) == 1)
		{
			g_env = del_env(g_env, &head);
			continue ;
		}
		g_env = g_env->next;
	}
	g_env = head;
	return (0);
}

int	builtin(t_scmd  *scmd)
{
	if (!ft_strcmp(scmd->args[0], "echo"))
		return (echo_built(scmd));
	else if (!ft_strcmp(scmd->args[0], "cd"))
		;
	else if (!ft_strcmp(scmd->args[0], "pwd"))
		return (pwd_built());
	else if (!ft_strcmp(scmd->args[0], "export"))
		;
	else if (!ft_strcmp(scmd->args[0], "unset"))
		unset_built(scmd);
	else if (!ft_strcmp(scmd->args[0], "env"))
		env_built();
	else if (!ft_strcmp(scmd->args[0], "exit"))
		;
	else
		;
	return (0);
}
