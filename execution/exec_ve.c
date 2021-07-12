/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 13:06:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/09 13:47:22 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static int	check_if_not_a_directory(char *path)
{
	char		*path2;
	int			ret;
	int			i;
	struct stat	st;

	ret = 0;
	i = 0;
	while (path[i] == '.' || path[i] == '/')
		i++;
	while (path[i])
	{
		while (path[i] && path[i] != '/')
			i++;
		if (path[i] == '/')
		{
			path2 = ft_substr(path, 0, i);
			ret = stat(path2, &st);
			free(path2);
			if (ret == 0 && st.st_mode / 10000 == 3)
				return (1);
			i++;
		}
	}
	return (0);
}

int	check_path(char *path, int ret)
{
	struct stat	st;

	ret = stat(path, &st);
	if (ret == 0 && st.st_mode / 10000 != 3)
	{
		if (look_for_slach(path) == 1 || path[0] == '.' \
			|| !ft_envp_getvalue(g_shell.envp, "PATH"))
			ret = -2;
		else
			ret = -3;
	}
	if (ret == 0 && st.st_mode / 10000 == 3)
	{
		if (look_for_slach(path) == 1 || path[0] == '.' \
			|| !ft_envp_getvalue(g_shell.envp, "PATH"))
			ret = 0;
		else
			ret = -3;
	}
	if (ret == -1 && path && look_for_slach(path) == 0 \
		&& ft_envp_getvalue(g_shell.envp, "PATH"))
		ret = -3;
	if ((ret == -3 || ret == -1) && check_if_not_a_directory(path) == 1)
		ret = -4;
	return (ret);
}

static int	exec_check_slash(char *path, char **args)
{
	int	ret;

	ret = check_path(path, 0);
	if (ret == 0)
	{
		execve(path, args, listenvp_to_tab());
		print_error(path, strerror(errno), 126);
	}
	else
	{
		if (ret == -1)
			print_error(path, "No such file or directory", 127);
		else if (ret == -2)
			print_error(path, "is a directory", 126);
		else if (ret == -3)
			print_error(path, "command not found", 127);
		else if (ret == -4)
			print_error(path, "Not a directory", 126);
	}
	return (g_shell.scmd_status);
}

static int	exec_check_paths(t_scmd *scmd)
{
	char	**paths;
	int		i;

	paths = ft_split(get_env_value("PATH"), ':');
	i = -1;
	while (paths && paths[++i])
	{
		paths[i] = join_free_s1(paths[i], "/");
		paths[i] = join_free_s1(paths[i], scmd->args[0]);
		if (check_path(paths[i], 0) == 0)
			break ;
	}
	if (i > -1 && paths[i])
		i = exec_check_slash(paths[i], scmd->args);
	else
		i = exec_check_slash(scmd->args[0], scmd->args);
	free_2d(paths);
	return (i);
}

int	exec_ve(t_scmd *scmd)
{
	if (scmd->args && scmd->args[0])
	{
		if (look_for_slach(scmd->args[0]) == 1)
			return (exec_check_slash(scmd->args[0], scmd->args));
		else
			return (exec_check_paths(scmd));
	}
	return (0);
}
