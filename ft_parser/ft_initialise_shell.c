/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialise_shell.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 16:56:04 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 20:45:07 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_initialise_terminal(void)
{
	int	error;

	g_shell.terminal = ft_envp_getvalue(g_shell.envp, "TERM");
	if (!g_shell.terminal)
		ft_manage_parsing_error(ETCID);
	g_shell.terminal = ft_strdup(g_shell.terminal);
	if (!g_shell.terminal)
		ft_manage_parsing_error(ETCID);
	error = tgetent(NULL, g_shell.terminal);
	if (error == 0)
		ft_manage_parsing_error(EUTERM);
	if (error == -1)
		ft_manage_parsing_error(ETERMINFO);
}

void	ft_initialise_shell(char **argv, char **sys_envp)
{
	int	error;

	ft_bzero(&g_shell, sizeof(t_shell));
	g_shell.delimiters = ft_get_delimiters();
	if (!g_shell.delimiters)
		ft_manage_parsing_error(EMAF);
	g_shell.envp = ft_load_sys_envp(sys_envp, &error);
	if (error)
		ft_manage_parsing_error(error);
	def_in_out();
	g_shell.argv = argv;
	g_shell.ifs = "\t \n";
	ft_initialise_terminal();
	g_shell.prompt = "\001\e[32m\033[1m\002Minishell%\001\e[0m\033[0m\002 ";
	ft_install_parent_signal_handlers();
	ft_settermios_attr();
	g_shell.pwd = getcwd(NULL, 0);
	if (!g_shell.pwd)
		ft_putstr_fd("minishell-init: error retrieving current directory: \
getcwd: cannot access parent directories: No such file or directory\n", 2);
}
