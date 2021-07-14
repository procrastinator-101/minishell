/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_execute_heredoc_utils.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:22:29 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 15:34:24 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static char	*found_dollar(char *str, char *tmp, int i, int j)
{
	if (str[i] == '?')
	{
		tmp = ft_itoa(g_shell.scmd_status);
		i++;
	}
	else
	{
		while (str && str[i] && str[i] != ' ' && str[i] != '$' && str[i] != '"'
			&& str[i] != '\'')
			i++;
		tmp = ft_substr(str, j, i - j);
		tmp = free_return(ft_strdup(get_env_value(tmp)), tmp);
	}
	tmp = join_free_all(ft_substr(str, 0, j - 1), tmp);
	tmp = join_free_all(tmp, ft_substr(str, i, ft_strlen(str)));
	return (tmp);
}

static char	*check_dollar(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ' \
				&& str[i + 1] != '$' && str[i + 1] != '"' \
				&& str[i + 1] != '\'')
		{
			i++;
			j = i;
			tmp = found_dollar(str, tmp, i, j);
			str = free_return(tmp, str);
			if (str[i - 1] == '\0')
				i--;
			continue ;
		}
		i++;
	}
	return (str);
}

int	ft_handle_heredoc(t_redirection *redirection, char *line, int fd)
{
	if (line && !ft_strcmp(line, redirection->right_operand))
	{
		free(line);
		return (1);
	}
	if (!redirection->isroperand_quoted)
		line = check_dollar(line);
	ft_putendl_fd(line, fd);
	free(line);
	return (0);
}
