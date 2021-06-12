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

void	free_2d(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		free(tabl[i++]);
	free(tabl);
}

int ft_indexchr(const char *s, char a)
{
	int	i;
	int	len;

    len = (int)ft_strlen(s);
	i = -1;
	while (++i < len + 1)
		if (s[i] == a)
			return (i);
	return (i);
}

char	*join_free_s1(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	**listenvp_to_tab(void)
{
	char	*line;
	t_envp	*tmp_env;
	char	**envp;

	tmp_env = g_env;
	line = ft_strdup("");
	while (tmp_env)
	{
		line = join_free_s1(line, tmp_env->name);
		line = join_free_s1(line, "=");
		line = join_free_s1(line, tmp_env->value);
		line = join_free_s1(line, "\n");
		tmp_env = tmp_env->next;
	}
	envp = ft_split(line, '\n');
	free(line);
	return (envp);
}

char	*tab_to_line(char **tabl)
{
	int		i;
	char	*line;

	i = -1;
	line = ft_strdup("");
	while (tabl[++i])
	{
		line = join_free_s1(line, tabl[i]);
		if (tabl[i + 1])
			line = join_free_s1(line, " ");
	}
	return (line);
}

int	tablen(char **tabl)
{
	int	i;

	i = 0;
	while (tabl[i])
		i++;
	return (i);
}
