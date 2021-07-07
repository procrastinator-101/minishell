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

int	ft_indexchr(const char *s, char a)	//unused
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
	if (!str)
	{
		print_error("MALLOC", strerror(errno), 1);
		ft_manage_parsing_error(0);
	}
	free(s1);
	return (str);
}

char	*join_free_all(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (!str)
	{
		print_error("MALLOC", strerror(errno), 1);
		ft_manage_parsing_error(0);
	}
	free(s1);
	free(s2);
	return (str);
}

char	*free_return(char *to_ret, char *to_free)
{
	free(to_free);
	return (to_ret);
}

char	*catch_null_ordup(char *str)
{
	if (str)
		return (ft_strdup2(str));
	return (str);
}

char	**listenvp_to_tab(void)
{
	char	*line;
	t_envp	*tmp_env;
	char	**envp;

	tmp_env = g_shell.envp;
	line = ft_strdup("");
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
	free(line);
	return (envp);
}

char	*tab_to_line(char **tabl)	// unused
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

char	*ft_strdup2(const char *src)
{
	int		s;
	char	*dest;
	int		i;

	if (src == NULL)
		return (ft_strdup2(""));
	i = 0;
	s = 0;
	while (src[s] != '\0')
		s++;
	if (!(dest = (char *)malloc(sizeof(dest) * (s + 1))))
		return (NULL);
	while (i <= s)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	look_for_equal(char *data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] == '=')
			return (i);
		i++;
	}
	return (0);
}
