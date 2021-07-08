/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 13:03:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/06 17:07:23 by yarroubi         ###   ########.fr       */
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
	while (1)
	{
		line = readline(g_shell.prompt);
		if (!line)
			break ;
		if (*line)
			add_history(line);
		error = ft_parser(line, ft_strlen(line) + 1);
		if (error)
			ft_manage_parsing_error(error);
		free(line);
	}
	ft_cleanup();
	return (EXIT_SUCCESS);
}
