/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_execute_heredoc.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 19:27:33 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 15:34:25 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

/*
**	heredoc is now executed in the parent
*/

int	ft_heredoc_terminate(int fd)
{
	int	ret;

	close(fd);
	ret = ft_resetcursor_position(ft_strlen("> "));
	if (ret)
		return (ETERCAP);
	ret = ft_updatecursor_position();
	if (ret)
		return (ETERCAP);
	g_shell.heredoc_status = 1;
	g_shell.count = 1;
	return (0);
}

int	ft_manage_heredoc_signal(int fd, int id)
{
	char	*termcap;

	if (id && g_shell.heredoc_status == 1)
	{
		termcap = tgetstr("cm", 0);
		if (!termcap)
			return (ETERCAP);
		termcap = tgoto(termcap, 0, g_shell.y - 1);
		if (!termcap)
			return (ETERCAP);
		write(STDOUT_FILENO, termcap, ft_strlen(termcap));
	}
	close(fd);
	return (ECSIG);
}

static int	ft_protect_cursor_update(int fd)
{
	int	ret;

	ret = ft_updatecursor_position();
	if (!ret)
		return (ret);
	close(fd);
	return (ret);
}

static int	ft_execute_heredoc(t_redirection *redirection, int id)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(redirection->file_name, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (EOFF);
	while (1)
	{
		ret = ft_protect_cursor_update(fd);
		if (ret)
			return (ETERCAP);
		line = readline("> ");
		if (g_shell.issignal)
			return (ft_manage_heredoc_signal(fd, id));
		if (!line)
			return (ft_heredoc_terminate(fd));
		ret = ft_handle_heredoc(redirection, line, fd);
		if (ret)
			break ;
	}
	g_shell.heredoc_status = 2;
	close(fd);
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
	ret = ft_execute_heredoc(redirection, id);
	if (g_shell.issignal)
	{
		dup2(g_shell.standin, STDIN_FILENO);
		close(g_shell.standin);
		g_shell.issignal = 0;
	}
	return (ret);
}
