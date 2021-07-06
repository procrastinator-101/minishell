/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 15:10:37 by hhoummad          #+#    #+#             */
/*   Updated: 2021/07/06 15:10:39 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	export_print(char **env_sorted)
{
	int	i;

	i = 0;
	while (env_sorted[i])
	{
		if (ft_isenv(env_sorted[i]) == 1)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(env_sorted[i], 1);
			ft_putstr_fd("=", 1);
			ft_putstr_fd("\"", 1);
			ft_putstr_fd(get_env_value(env_sorted[i]), 1);
			ft_putstr_fd("\"", 1);
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
	env_sorted = malloc(sizeof(char *) * env_size + 1);
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

int	export_built(t_scmd *scmd)
{
	int	i;

	i = 1;
	if (tablen(scmd->args) == 1)
		export_only(env_size());
	else
	{
		while (scmd->args[i])
		{
			
			i++;
		}
	}
	return (0);
}
