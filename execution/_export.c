/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _export.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:10:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/08 19:52:35 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	export_print(char **env_sorted)
{
	int		i;
	char	*tmp;

	i = 0;
	while (env_sorted[i])
	{
		if (ft_isenv(env_sorted[i]) == 1)
		{
			tmp = get_env_value(env_sorted[i]);
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env_sorted[i], 1);
			if (tmp)
			{
				ft_putstr_fd("=", 1);
				ft_putstr_fd("\"", 1);
				ft_putstr_fd(tmp, 1);
				ft_putstr_fd("\"", 1);
			}
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}

static void	export_only(int env_size)
{
	char	**env_sorted;
	int		i;
	t_envp	*envp;

	i = 0;
	envp = g_shell.envp;
	env_sorted = malloc(sizeof(char *) * (env_size + 1));
	if (!env_sorted)
		checkalloc(NULL);
	while (i < env_size)
	{
		env_sorted[i] = envp->name;
		envp = envp->next;
		i++;
	}
	env_sorted[env_size] = NULL;
	sort_table(env_sorted, env_size);
	export_print(env_sorted);
	free(env_sorted);
}

static void	export_add(char *data, int index)
{
	char	*tmp;

	tmp = checkalloc(ft_substr(data, 0, index));
	if (ft_isname(tmp) == 0)
	{
		print_error_2("export", tmp, "not a valid identifier", 1);
		return ;
	}
	ft_envp_setvalue(g_shell.envp, tmp,
		checkalloc(ft_strdup2(data + index + 1)));
	free(tmp);
}

static void	export_with_args(t_scmd *scmd)
{
	int	i;
	int	index;

	i = 1;
	while (scmd->args[i])
	{
		index = look_for_equal(scmd->args[i]);
		if (index != 0)
			export_add(scmd->args[i], index);
		else
		{
			if (ft_isname(scmd->args[i]) == 0)
				print_error_2("export", scmd->args[i],
					"not a valid identifier", 1);
			else
			{
				ft_envp_setvalue(g_shell.envp, scmd->args[i],
					catch_null_ordup(ft_envp_getvalue(g_shell.envp,
							scmd->args[i])));
				ft_set_isenv(scmd->args[i], 1);
			}
		}
		i++;
	}
}

int	export_built(t_scmd *scmd)
{
	if (tablen(scmd->args) == 1)
		export_only(env_size());
	else
	{
		if (check_options(scmd) == 0)
			export_with_args(scmd);
	}
	return (g_shell.scmd_status);
}
