/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_shell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 13:26:49 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_initialise_shell(char **argv, char **sys_envp)
{
	int	error;

	g_shell.delimiters = ft_get_delimiters();
	if (!g_shell.delimiters)
	{
		ft_display_error_msg(EMAF);
		exit(EXIT_FAILURE);
	}
	g_shell.envp = ft_load_sys_envp(sys_envp, &error);
	if (error)
	{
		ft_display_error_msg(error);
		free(g_shell.delimiters);
		exit(EXIT_FAILURE);
	}
	//g_shell.offset = 0;
	g_shell.x = 0;
	g_shell.y = 0;
	g_shell.def_in = dup(STDIN_FILENO);
	g_shell.def_out = dup(STDOUT_FILENO);
	g_shell.argv = argv;
	g_shell.ifs = "\t \n";
	g_shell.ischild_signal = 0;
	g_shell.terminal = ft_envp_getvalue(g_shell.envp, "TERM");
	//
	if (!g_shell.terminal)
	{
		ft_display_error_msg(EMAF);
		ft_envp_clear(&(g_shell.envp));
		free(g_shell.delimiters);
		exit(EXIT_FAILURE);
	}
	g_shell.prompt = "\001\e[32m\033[1m\002Minishell%\001\e[0m\033[0m\002 ";
	g_shell.rdc_operand = 0;
}
