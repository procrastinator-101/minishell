/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_install_parent_signal_handlers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:05:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 13:26:56 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_handle_signal(int signal)
{
	if (signal == SIGINT && !g_shell.ischild_signal)
	{
		g_shell.scmd_status = 1;
		g_shell.standin = dup(STDIN_FILENO);
		if (g_shell.isheredoc)
			write(STDOUT_FILENO, "\n", 1);
		close(STDIN_FILENO);
		g_shell.issignal = 1;
	}
}

void	ft_install_parent_signal_handlers(void)
{
	signal(SIGINT, ft_handle_signal);
	signal(SIGQUIT, SIG_IGN);
}
