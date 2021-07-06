/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_install_parent_signal_handlers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:05:58 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/06 17:52:55 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static void	ft_handle_signal(int signal)
{
	if (signal == SIGINT && !g_shell.ischild_signal)
	{
		rl_replace_line("", 0);
		write(1, "\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_install_parent_signal_handlers(void)
{
	signal(SIGINT, ft_handle_signal);
	signal(SIGQUIT, SIG_IGN);
}
