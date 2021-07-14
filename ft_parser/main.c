/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 11:13:32 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/14 16:06:54 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_shell	g_shell;

static int	ft_handle_miscellaneous(void)
{
	if (g_shell.issignal)
	{
		dup2(g_shell.standin, STDIN_FILENO);
		close(g_shell.standin);
		g_shell.issignal = 0;
		return (1);
	}
	if (g_shell.scmd_status)
		g_shell.count = 0;
	return (0);
}

static int	ft_handle_mainbody(char *line)
{
	int	error;

	if (!line)
		return (1);
	if (*line)
		add_history(line);
	else
	{
		g_shell.scmd_status = 0;
		free(line);
		return (0);
	}
	error = ft_parser(line, ft_strlen(line) + 1);
	if (error)
		ft_manage_parsing_error(error);
	free(line);
	return (0);
}

int	main(int argc, char **argv, char **sys_envp)
{
	int		error;
	char	*line;

	if (argc > 1)
		ft_manage_parsing_error(0);
	ft_initialise_shell(argv, sys_envp);
	while (1)
	{
		error = ft_updatecursor_position();
		if (error)
			ft_manage_parsing_error(ETERCAP);
		line = readline(g_shell.prompt);
		error = ft_handle_miscellaneous();
		if (error)
			continue ;
		error = ft_handle_mainbody(line);
		if (error)
			break ;
	}
	ft_terminate();
	return (0);
}
