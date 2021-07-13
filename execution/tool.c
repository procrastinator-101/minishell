/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhoummad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:31:38 by hhoummad          #+#    #+#             */
/*   Updated: 2021/06/11 11:31:42 by hhoummad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

char	**listenvp_to_tab(void)
{
	char	*line;
	t_envp	*tmp_env;
	char	**envp;

	tmp_env = g_shell.envp;
	line = checkalloc(ft_strdup(""));
	while (tmp_env)
	{
		if (tmp_env->value)
		{
			line = join_free_s1(line, tmp_env->name);
			line = join_free_s1(line, "=");
			line = join_free_s1(line, tmp_env->value);
			line = join_free_s1(line, "\n");
		}
		tmp_env = tmp_env->next;
	}
	envp = ft_split(line, '\n');
	if (!envp)
		checkalloc(NULL);
	free(line);
	return (envp);
}

int	tablen(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		i++;
	return (i);
}

int	env_size(void)
{
	t_envp	*env;
	int		i;

	env = g_shell.envp;
	i = 0;
	while (env)
	{
		i++;
		env = env->next;
	}
	return (i);
}

void	sort_table(char **table, int table_size)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (i < table_size - 1)
	{
		j = i + 1;
		while (j < table_size)
		{
			if (ft_strcmp(table[i], table[j]) > 0)
			{
				tmp = table[i];
				table[i] = table[j];
				table[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
