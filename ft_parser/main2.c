/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 13:18:23 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

t_shell	g_shell;

int	main(int argc, char **argv, char **sys_envp)
{
	int		error;
	char	*line;

	if (argc > 1)
		ft_manage_parsing_error(0);
	ft_initialise_shell(argv, sys_envp);
	ft_install_parent_signal_handlers();
	ft_settermios_attr();
	ft_updatecursor_position();//
	g_shell.issignal = 0;
	while (1)
	{
		line = readline(g_shell.prompt);
		dup2(g_shell.standin, STDIN_FILENO);
		if (!line && g_shell.issignal)
		{
			//printf("x = %d y = %d\n", g_shell.x, g_shell.y);
			if (g_shell.x > 1)
				write(STDOUT_FILENO, "\n", 1);
			else
			{
				rl_on_new_line();
				rl_replace_line("", 0);
			}
			ft_updatecursor_position();//
			printf("x = %d y = %d\n", g_shell.x, g_shell.y);
			//rl_redisplay();
			g_shell.issignal = 0;
			continue ;
		}
		if (!line)
			break ;
		if (*line)
			add_history(line);
		error = ft_parser(line, ft_strlen(line) + 1);
		if (error)
			ft_manage_parsing_error(error);
		free(line);
		ft_updatecursor_position();//
	}
	ft_terminate();
	return (0);
}
