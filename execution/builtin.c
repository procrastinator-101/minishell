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

#include "execution.h"

// int	cd_built(t_scmd  *scmd)
// {	
// }

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

	head = g_shell.envp;
	while (g_shell.envp)
	{
		if (check_if_exist(scmd, g_shell.envp->name) == 1)
		{
			g_shell.envp = del_env(g_shell.envp, &head);
			continue ;
		}
		g_shell.envp = g_shell.envp->next;
	}
	g_shell.envp = head;
	return (0);
}

int	exec_check_slash(char *path, char **args)
{
	int	ret;

	ret = check_path(path);
	if (ret == 0)
		execve(path, args, listenvp_to_tab());
	else
		printf("error %d\n", ret); //exit error // if ret -1 path: No such file or directory // if ret -2 path: is a directory
	return (0);
}

int	exec_check_paths(t_scmd *scmd)
{
	char	**paths;
	int		i;

	paths = ft_split(get_env_value("PATH"), ':');
	i = -1;
	while (paths && paths[++i])
	{
		paths[i] = join_free_s1(paths[i], "/");
		paths[i] = join_free_s1(paths[i], scmd->args[0]);
		if (check_path(paths[i]) == 0)
			break ;
	}
	if (paths[i])
		i = exec_check_slash(paths[i], scmd->args);
	else
		i = exec_check_slash(scmd->args[0], scmd->args);
	free_2d(paths);
	return (i);
}

int	exec_ve(t_scmd  *scmd)
{
	if (scmd->args[0][0] == '/')
		return (exec_check_slash(scmd->args[0], scmd->args));
	else
		return (exec_check_paths(scmd));
	return (0);
}

int	builtin(t_scmd  *scmd)
{
	if (scmd->args[0])
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
			return (unset_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "env"))
			return (env_built(scmd));
		else if (!ft_strcmp(scmd->args[0], "exit"))
			;
		else
			return (exec_ve(scmd));
	}
	return (0);
}
