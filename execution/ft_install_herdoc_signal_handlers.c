/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_install_herdoc_signal_handlers.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarroubi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 17:16:16 by yarroubi          #+#    #+#             */
/*   Updated: 2021/07/08 17:43:26 by yarroubi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static void	ft_handle_signal(int signal)
{
	if (signal == SIGINT)
	{
		g_shell.isheredoc_open = 0;
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_install_herdoc_signal_handlers(void)
{
	signal(SIGINT, ft_handle_signal);
}
