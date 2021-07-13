/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_install_parent_signal_handlers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:05:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/13 16:01:08 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_handle_signal(int signal)
{
	if (signal == SIGINT && !g_shell.ischild_signal)
	{
		g_shell.scmd_status = 1;
		rl_replace_line("", 0);
		ft_updatecursor_position();
		g_shell.issignal = 1;
		write(STDOUT_FILENO, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_install_parent_signal_handlers(void)
{
	signal(SIGINT, ft_handle_signal);
	signal(SIGQUIT, SIG_IGN);
}
