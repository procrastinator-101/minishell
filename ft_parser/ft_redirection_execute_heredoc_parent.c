/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_execute_heredoc.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:27:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 18:24:50 by yarroubi         ###   ########.fr       */
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
			&& str[i] != '\'' && str[i] != ';')
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
				&& str[i + 1] != '\'' && str[i + 1] != ';')
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

static int	ft_execute_heredoc(t_redirection *redirection)
{
	int		fd;
	char	*line;

	fd = open(redirection->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (EOFF);
	while (1)
	{
		ft_updatecursor_position();//
		line = readline("> ");
		if (g_shell.issignal)
		{
			close(fd);
			return (ECSIG);
		}
		if (!line)
			break ;
		if (line && !ft_strcmp(line, redirection->right_operand))
		{
			free(line);
			break ;
		}
		if (!redirection->isroperand_quoted)
			line = check_dollar(line);
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	if (!line)
		ft_resetcursor_position(ft_strlen("> "));
	return (0);
}

int	ft_redirection_execute_heredoc(t_redirection *redirection, int id)
{
	int		ret;
	char	*str;

	str = ft_itoa(id);
	if (!str)
		return (EMAF);
	redirection->file_name = ft_strjoin("/tmp/tmp_hdoc_", str);
	free(str);
	if (!redirection->file_name)
		return (EMAF);
	g_shell.issignal = 0;
	g_shell.isheredoc = 1;
	ret = ft_execute_heredoc(redirection);
	g_shell.isheredoc = 0;
	if (g_shell.issignal)
	{
		dup2(g_shell.standin, STDIN_FILENO);
		close(g_shell.standin);
	}
	g_shell.issignal = 0;
	return (ret);
}
