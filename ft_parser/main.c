/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 20:41:02 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_shell	g_shell;

static int	ft_handle_miscellaneous(void)
{
	g_shell.count++;
	if (g_shell.count > 1000)
		g_shell.count = 1;
	if (g_shell.issignal)
	{
		dup2(g_shell.standin, STDIN_FILENO);
		close(g_shell.standin);
		return (1);
	}
	g_shell.issignal = 0;
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
		g_shell.issignal = 0;
		ft_updatecursor_position();
		line = readline(g_shell.prompt);
		error = ft_handle_miscellaneous();
		if (error)
			continue ;
		if (!line)
			break ;
		if (*line)
			add_history(line);
		error = ft_parser(line, ft_strlen(line) + 1);
		if (error)
			ft_manage_parsing_error(error);
		free(line);
	}
	ft_terminate();
	return (0);
}
