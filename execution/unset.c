/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 17:05:18 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/01 17:05:20 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static t_envp	*del_env(t_envp *env, t_envp **head)
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

static int	check_if_same(t_scmd *scmd, char *name)
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

static int	check_options(t_scmd *scmd)
{
	int	i;

	i = 1;
	while (scmd->args[i])
	{
		if (scmd->args[i][0] == '-')
		{
			ft_display_error_msg(0);
			ft_putstr_fd("unset: No options allowed\n", 2);
			g_shell.scmd_status = 1;	// to check
			return (1);
		}
		i++;
	}
	return (0);
}

int	unset_built(t_scmd *scmd)
{
	t_envp	*head;

	head = g_shell.envp;
	if (check_options(scmd) == 1)
		return (1);
	while (g_shell.envp)
	{
		if (check_if_same(scmd, g_shell.envp->name) == 1)
		{
			if (ft_strcmp(g_shell.envp->name, "PWD") == 0
				|| ft_strcmp(g_shell.envp->name, "OLDPWD") == 0)
			{
				g_shell.envp->isenv = 0;
				free(g_shell.envp->value);
				g_shell.envp->value = ft_strdup("");
				g_shell.envp = g_shell.envp->next;
			}
			else
				g_shell.envp = del_env(g_shell.envp, &head);
			continue ;
		}
		g_shell.envp = g_shell.envp->next;
	}
	g_shell.envp = head;
	return (0);
}
